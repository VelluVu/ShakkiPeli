#include "KayttoLiittyma.h"
#include <iostream>
#include <string>

int main() {
	
	Asema asema;
	KayttoLiittyma kayttis(&asema);
	asema.SetSiirtovuoro(0);
	
	std::wcout << "Valkoinen aloittaa. " << std::endl;

	for (size_t i = 0; i < 50; i++)
	{

		//system("cls");
		kayttis.PiirraLauta();

		//Vuorossa olevan Siirtolista
		std::list<Siirto> siirtoLista;

		//Generoidaan siirrot
		asema.AnnaLaillisetSiirrot(siirtoLista);
		std::wcout << siirtoLista.size() << " siirtoa" << std::endl;

		//Pelaajalta kysytty siirto
		Siirto s = kayttis.AnnaVastustajanSiirto();

		//Onko listassa?
		for(Siirto m: siirtoLista) 
		{
			if (s == m) 
			{
				asema.PaivitaAsema(&s);
			}
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