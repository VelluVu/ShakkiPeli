#include "KayttoLiittyma.h"
#include <iostream>
#include <string>

int main() {
	
	Asema asema;
	KayttoLiittyma kayttis(&asema);
	asema.SetSiirtovuoro(0);
	
	std::wcout << "Valkoinen aloittaa. " << std::endl;

	for (size_t i = 0; i < 2; i++)
	{

		//system("cls");
		kayttis.PiirraLauta();
		std::list<Siirto> siirtoLista;
		asema.AnnaLaillisetSiirrot(siirtoLista);
		std::wcout << siirtoLista.size() << " siirtoa" << std::endl;

		Siirto s = kayttis.AnnaVastustajanSiirto();

		while (std::find(siirtoLista.begin(), siirtoLista.end(), s) == siirtoLista.end())
		{
			s = kayttis.AnnaVastustajanSiirto();
		}

		asema.PaivitaAsema(&s);

		if (asema.GetSiirtovuoro() == 0) 
		{
			asema.SetSiirtovuoro(1);
		}
		else {
			asema.SetSiirtovuoro(0);
		}
	}

	system("Pause");
	return 0;
}