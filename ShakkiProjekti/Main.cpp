#include "KayttoLiittyma.h"
#include <iostream>
#include <string>

int main() {
	
	Asema asema;
	KayttoLiittyma kayttis(&asema);
	asema.SetSiirtovuoro(0);

	std::wcout << "Valitse Nappulan Väri: <0/1>" << std::endl;
	int valinta = 0;
	std::cin >> valinta;

	std::wcout << "Type secret code to activate cheatMode: " << std::endl;
	std::wstring trySecretCode;
	std::wstring secretCode = L"IDDQD";
	std::wcin >> trySecretCode;
	int haxor = trySecretCode.compare(secretCode);

	std::wcout << "Valkoinen aloittaa. " << std::endl;

	for (int i = 0; i < 50; i++)
	{

		//system("cls");
		kayttis.PiirraLauta();

		//Vuorossa olevan Siirtolista
		std::list<Siirto> siirtoLista;
		Siirto s;
		//Generoidaan siirrot
		asema.AnnaLaillisetSiirrot(siirtoLista);
		std::wcout << siirtoLista.size() << " siirtoa" << std::endl;

		//tulosta vielä kaikki siirrot
		for (Siirto s : siirtoLista)
		{

			s.TulostaRuudut();

		}

		//Valkoisten Siirtovuoro
		if (asema.GetSiirtovuoro() == valinta) 
		{
			//Alphabetalla ainaki yrityshyvä10
			MinMaxPaluu cheatMove = asema.MiniMax(3, -1000000.0, 1000000.0, true);
			if (haxor <= 0)
			{
				std::wcout << "HAXMOVE : "; cheatMove.parasSiirto.TulostaRuudut();
				std::wcout << "MINMAXARVO : " << cheatMove.evaluointiArvo << std::endl;
			}
			s = kayttis.AnnaVastustajanSiirto();

			//Katsotaan onko siirto validi
			for (Siirto m : siirtoLista)
			{
				if (s == m)
				{
					asema.PaivitaAsema(&s);
				}
			}
		}
		else //Mustien Siirtovuoro
		{	
			MinMaxPaluu cheatMove = asema.MiniMax(3, -1000000.0, 1000000.0, false);
			if (haxor <= 0)
			{
				std::wcout << "HAXMOVE : "; cheatMove.parasSiirto.TulostaRuudut();
				std::wcout << "MINMAXARVO : " << cheatMove.evaluointiArvo << std::endl;
			}
			//Musta käyttää MINMAX VALITSEMAA SIIRTOA

			//Musta pelaa random peliä
			/*int rng = rand() % siirtoLista.size();
			auto siirtoLista_front = siirtoLista.begin();
			std::advance(siirtoLista_front, rng);
			s = *siirtoLista_front;*/
			s = cheatMove.parasSiirto;
			asema.PaivitaAsema(&s);
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