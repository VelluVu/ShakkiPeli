#include "KayttoLiittyma.h"
#include <iostream>
#include <string>

int main() {
	
	Asema* asema = new Asema();
	KayttoLiittyma kayttis(asema);
	kayttis.PiirraLauta();
	kayttis.asema->SetSiirtovuoro(0);
	
	std::wcout << "Valkoinen aloittaa. " << std::endl;
	for (size_t i = 0; i < 50; i++)
	{
		
		kayttis.asema->PaivitaAsema(&kayttis.AnnaVastustajanSiirto());
		//system("cls");
		kayttis.PiirraLauta();
	}


	

	system("Pause");
	delete asema;
	return 0;
}