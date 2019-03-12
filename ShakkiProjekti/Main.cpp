#include "KayttoLiittyma.h"
#include <iostream>
#include <string>
#include <chrono>
#include <vector>

inline auto currentTime() {
	return std::chrono::high_resolution_clock::now();
}

struct Timer {
	Timer() { Reset(); }
	void Reset() {
		startTime = currentTime();
	}
	double GetElapsed() {
		return std::chrono::duration_cast<std::chrono::seconds>(currentTime() - startTime).count();
	}
	std::chrono::time_point<std::chrono::steady_clock> startTime;
};

int main() {

	int valinta = 0;
	bool onkoPelaajaa = false;
	int undo = 0;
	int asemanIndex = 0;
	double peliTilanne = 0;

	Timer stopWatch;
	Asema asema;
	std::vector<Asema> asemat;

	asema.asemanArvo = 0;
	KayttoLiittyma kayttis(&asema);
	
	std::wcout << "Valitse Nappulan Väri: <0/1>" << std::endl;
	std::cin >> valinta;
	if (valinta == 1 || valinta == 0) {
		onkoPelaajaa = true;
	}

	//Peli alkaa valkoisten vuorolla
	asema.SetSiirtovuoro(0);
	
	std::wcout << "Valkoinen aloittaa. " << std::endl;

	//tallentaa alkuaseman listaan
	asemat.push_back(asema);

	for (int i = 0; i < 500; i++)
	{
		//TULOSTAA TALLENNETUT ASEMAT
		std::wcout << "INDEX | KOKO " << asemanIndex << " | " << asemat.size() - 1 << std::endl;

		if (!asemat.empty())
		{
			for (Asema a : asemat)
			{
				std::wcout << "Asema " << asemanIndex  << ": " << a.asemanArvo << " |";
			}
		}

		std::wcout << std::endl << std::endl;

		kayttis.PiirraLauta();
	
		std::wcout << std::endl;
		
		//MAHDOLLISUUS PERUA SIIRTO! JOS ENSIMMÄINEN LIIKE ON TEHTY
		if (i > 0) {
			std::wcout << "Haluatko peruuttaa siirtoja? määrä <int>" << std::endl;

			std::wcin >> undo;

			if (undo > 0 && asemanIndex >= 0 && asemanIndex - undo >= 0)
			{
				asemanIndex -= undo;
				asema = asemat.at(asemanIndex);
				while (undo > 0)
				{
					if (asemat.empty()) {
						undo = 0;
					}
					else {
						asemat.pop_back();
						undo--;
					}
				}
			}
		}

		system("cls");

		//Vuorossa olevan Siirtolista
		std::list<Siirto> siirtoLista;

		//AI VALINTA
		MinMaxPaluu cheatMove;

		//Generoidaan siirrot
		asema.AnnaLaillisetSiirrot(siirtoLista);

		//Alustetaan AI siirto randomilla
		int rng = rand() % siirtoLista.size();
		auto siirtoLista_front = siirtoLista.begin();
		std::advance(siirtoLista_front, rng);
		cheatMove.parasSiirto = *siirtoLista_front;

		kayttis.PiirraLauta();

		std::wcout << siirtoLista.size() << " mahdollista siirtoa! " << std::endl;
		//tulosta vielä kaikki siirrot
		for (Siirto m : siirtoLista)
		{

			m.TulostaRuudut();

		}
		std::wcout << std::endl;
		
		//Valkoisten Siirtovuoro
		if (asema.GetSiirtovuoro() == 0) 
		{	
			//Nollaa kellon
			stopWatch.Reset();
	
			cheatMove = asema.AlphaBeta(4, -INFINITY, INFINITY, true);
			
			std::wcout << "AI-MOVE : "; cheatMove.parasSiirto.TulostaRuudut();
			
			if (valinta == 0 && onkoPelaajaa) 
			{
				Siirto s = kayttis.AnnaVastustajanSiirto();
				asema.PaivitaAsema(&s);			
			}
			else 
			{
				asema.PaivitaAsema(&cheatMove.parasSiirto);
			}
			
		}
		else //Mustien Siirtovuoro
		{	
			//Nollaa kellon
			stopWatch.Reset();

			//Alphabetalla ainaki yrityshyvä10 PRUNING EI TOIMI!!
			cheatMove = asema.AlphaBeta(4, -INFINITY, INFINITY, false);
			
			std::wcout << "AI-MOVE : "; cheatMove.parasSiirto.TulostaRuudut();
	
			if (valinta == 1 && onkoPelaajaa)
			{
				Siirto s = kayttis.AnnaVastustajanSiirto();
				asema.PaivitaAsema(&s);			
			}
			else
			{
				asema.PaivitaAsema(&cheatMove.parasSiirto);
			}
		}

		//Asettaa aseman arvon pelitilanteen arvoksi
		peliTilanne = cheatMove.evaluointiArvo;
		
		//Printtaa vuoroon käytetyn ajan
		std::wcout << "Vuoron Kesto: " << stopWatch.GetElapsed() << " sec"<< std::endl;

		//Testaa onko tultu tilanteeseen missä pelipäättyy
		if (peliTilanne <= -1000000.0) {
			std::wcout << "BLACK WIN! " << std::endl;
			system("Pause");
			break;
		}
		else if (peliTilanne >= 1000000.0) {
			std::wcout << "WHITE WIN! " << std::endl;
			system("Pause");
			break;
		}
		else if (peliTilanne == 12345678.0) {
			std::wcout << "DRAW !" << std::endl;
			system("Pause");
			break;
		}
		
		//Vaihdetaan vuoro
		if (asema.GetSiirtovuoro() == 0) 
		{
			asema.SetSiirtovuoro(1);
			std::wcout << "Seuraava siirto on mustan" << std::endl;
		}
		else {
			asema.SetSiirtovuoro(0);
			std::wcout << "Seuraava siirto on valkoinen" << std::endl;
		}

		//Tallentaa pelatun aseman listaan
		asemat.push_back(asema);
		//Kasvattaa indexiä
		asemanIndex++;

	}

	return 0;
}