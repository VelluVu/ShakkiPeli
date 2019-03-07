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
	
	Timer stopWatch;
	Asema asema;
	KayttoLiittyma kayttis(&asema);
	std::vector<Asema> asemat;
	asema.asemanArvo = 0;
	std::wcout << "Valitse Nappulan Väri: <0/1>" << std::endl;
	int valinta = 0;
	std::cin >> valinta;
	asema.SetSiirtovuoro(valinta);
	std::wcout << "Type secret code to activate cheatMode: " << std::endl;
	std::wstring trySecretCode;
	std::wstring secretCode = L"IDDQD";
	std::wcin >> trySecretCode;
	int haxor = trySecretCode.compare(secretCode);
	double peliTilanne = 99.99;
	double min = -1000000;
	double max =1000000;

	std::wcout << "Valkoinen aloittaa. " << std::endl;

	for (int i = 0; i < 100; i++)
	{

		if (!asemat.empty())
		{
			for (Asema a : asemat)
			{
				std::wcout << "Asema: " << a.asemanArvo << " |";
			}
		}
		std::wcout << std::endl;

		kayttis.PiirraLauta();
		//MAHDOLLISUUS PERUA SIIRTO!
		std::wcout << "Haluatko peruuttaa siirtoja? määrä <int>" << std::endl;
		int undo;
		std::wcin >> undo;

		if (undo > 0 && !asemat.empty())
		{
			while (undo == 0) {
				asemat.pop_back();
				undo--;
			}
			
			asema = asemat.front();
		}

		asemat.push_back(asema);

		system("cls");
		kayttis.PiirraLauta();
		
		//Vuorossa olevan Siirtolista
		std::list<Siirto> siirtoLista;
		Siirto s;
		MinMaxPaluu cheatMove;

		//Tarkistaa miten peli loppu

		if (peliTilanne <= -1000.0) {
			std::wcout << "BLACK WIN! " << std::endl;
			break;
		}
		if (peliTilanne >= 1000.0) {
			std::wcout << "WHITE WIN! " << std::endl;
			break;
		}
		if (siirtoLista.empty() && peliTilanne == 0)
		{
			std::wcout << "DRAW! " << std::endl;
			break;
		}

		//Generoidaan siirrot
		asema.AnnaLaillisetSiirrot(siirtoLista);

		//Alustetaan paras siirto randomilla
		int rng = rand() % siirtoLista.size();
		auto siirtoLista_front = siirtoLista.begin();
		std::advance(siirtoLista_front, rng);
		cheatMove.parasSiirto = *siirtoLista_front;

		std::wcout << siirtoLista.size() << " siirtoa" << std::endl;
		//tulosta vielä kaikki siirrot
		for (Siirto s : siirtoLista)
		{

			s.TulostaRuudut();

		}
		std::wcout << std::endl;
	
		//Valkoisten Siirtovuoro
		if (asema.GetSiirtovuoro() == valinta) 
		{	
			//s = kayttis.AnnaVastustajanSiirto();
			//laskee koko miettimis ajan ei pysäytä functioo.
			stopWatch.Reset();

			//Alphabetalla ainaki yrityshyvä10 PRUNING EI TOIMI!!
			cheatMove = asema.AlphaBeta(3, min, max, true);
			if (haxor <= 0)
			{
				std::wcout << "HAXMOVE : "; cheatMove.parasSiirto.TulostaRuudut();
				std::wcout << "MINMAXARVO : " << cheatMove.evaluointiArvo << std::endl;
			}
			asema.PaivitaAsema(&cheatMove.parasSiirto);

			//Katsotaan onko siirto validi
			/*for (Siirto m : siirtoLista)
			{
				if (s == m)
				{
					asema.PaivitaAsema(&s);
				}
			}*/
		}
		else //Mustien Siirtovuoro
		{	
			//laskee koko miettimis ajan ei pysäytä functioo.
			stopWatch.Reset();

			//Alphabetalla ainaki yrityshyvä10 PRUNING EI TOIMI!!
			cheatMove = asema.AlphaBeta(3, min, max, false);
			if (haxor <= 0)
			{
				std::wcout << "HAXMOVE : "; cheatMove.parasSiirto.TulostaRuudut();
				std::wcout << "MINMAXARVO : " << cheatMove.evaluointiArvo << std::endl;
			}
			//Musta käyttää MINMAX VALITSEMAA SIIRTOA
			//Alphabetalla ainaki yrityshyvä10, minimoijana kutsutaan min;
			
			//Musta pelaa random peliä
			/*int rng = rand() % siirtoLista.size();
			auto siirtoLista_front = siirtoLista.begin();
			std::advance(siirtoLista_front, rng);
			s = *siirtoLista_front;*/
			
			asema.PaivitaAsema(&cheatMove.parasSiirto);
		}

		peliTilanne = cheatMove.evaluointiArvo;
		
		//Printtaa mietityn ajan
		std::wcout << "Vuoron Kesto: " << stopWatch.GetElapsed() << " sec"<< std::endl;

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

	}

	system("Pause");
	return 0;
}