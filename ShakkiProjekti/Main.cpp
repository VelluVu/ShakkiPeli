#include "KayttoLiittyma.h"
#include <iostream>
#include <string>
#include <chrono>
#include <vector>

using Clock=std::chrono::high_resolution_clock;

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

	std::wcout << "Valkoinen aloittaa. " << std::endl;

	for (int i = 0; i < 100; i++)
	{
		
		kayttis.PiirraLauta();

		//MAHDOLLISUUS PERUA SIIRTO!
		std::wcout << "Haluatko peruuttaa siirtoja? määrä <int>" << std::endl;
		int undo;
		std::wcin >> undo;

		if (undo > 0)
		{
			if(asemat.size() > undo)
				for (int i = 0; i <= undo; i++)
				{
					asemat.pop_back();
				}
			asema = asemat.front();
		}
		//TÄHÄN LOPPUU
		system("cls");
		kayttis.PiirraLauta();
		
		if (asemat.size() != 0) 
		{
			for (Asema a : asemat)
			{
				std::wcout << "ARVO: " << a.asemanArvo << " , ";
			}
		}
		std::wcout << std::endl;
		asemat.push_back(asema);
	
		//Vuorossa olevan Siirtolista
		std::list<Siirto> siirtoLista;
		Siirto s;
		MinMaxPaluu cheatMove;

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

		//laskee koko miettimis ajan ei pysäytä functioo.
		auto t1 = Clock::now();
	
		//Alphabetalla ainaki yrityshyvä10 PRUNING EI TOIMI!!
		cheatMove = asema.AlphaBeta(3, -INFINITY, +INFINITY);
		
		if (haxor <= 0)
		{
			std::wcout << "HAXMOVE : "; cheatMove.parasSiirto.TulostaRuudut();
			std::wcout << "MINMAXARVO : " << cheatMove.evaluointiArvo << std::endl;	
		}
	
		//Valkoisten Siirtovuoro
		if (asema.GetSiirtovuoro() == valinta) 
		{	
			//s = kayttis.AnnaVastustajanSiirto();

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
		
			//Musta käyttää MINMAX VALITSEMAA SIIRTOA
			//Alphabetalla ainaki yrityshyvä10, minimoijana kutsutaan min;
			
			//Musta pelaa random peliä
			/*int rng = rand() % siirtoLista.size();
			auto siirtoLista_front = siirtoLista.begin();
			std::advance(siirtoLista_front, rng);
			s = *siirtoLista_front;*/
			
			asema.PaivitaAsema(&cheatMove.parasSiirto);
		}
		auto t2 = Clock::now();
		std::wcout << "VUORO KESTI : " << std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count() << " SEKUNTTIA !" << std::endl;

		if (cheatMove.evaluointiArvo <= -1000000) {
			std::wcout << "BLACK WIN! " << std::endl;
		}
		else if (cheatMove.evaluointiArvo >= 1000000){
			std::wcout << "WHITE WIN! " << std::endl;
		}
		else if (cheatMove.evaluointiArvo == 0) 
		{
			std::wcout << "DRAW! " << std::endl;
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
	}

	system("Pause");
	return 0;
}