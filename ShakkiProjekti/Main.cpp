#include "KayttoLiittyma.h"
#include <iostream>
#include <string>

int main() {
	
	Asema asema;
	KayttoLiittyma kayttis(&asema);
	asema.SetSiirtovuoro(0);
	
	std::wcout << "Valkoinen aloittaa. " << std::endl;

	for (int i = 0; i < 50; i++)
	{

		//system("cls");
		kayttis.PiirraLauta();

		//Vuorossa olevan Siirtolista
		std::list<Siirto> siirtoLista;

		//Generoidaan siirrot
		asema.AnnaLaillisetSiirrot(siirtoLista);
		std::wcout << siirtoLista.size() << " siirtoa" << std::endl;
		Siirto s;

		//tulosta vielä kaikki siirrot
		for (Siirto s : siirtoLista)
		{

			s.TulostaRuudut();

		}

		//Alphabetalla ainaki yrityshyvä10
		MinMaxPaluu cheatMove = asema.MiniMax(2, -INFINITY, INFINITY);
		std::wcout << "HAXMOVE : "; cheatMove.parasSiirto.TulostaRuudut();
		std::wcout << "MINMAX : " << cheatMove.evaluointiArvo << std::endl;

		//Pelaajalta kysytty siirto
		if (asema.GetSiirtovuoro() == 0) 
		{
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
		else 
		{
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