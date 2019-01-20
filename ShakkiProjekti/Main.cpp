#include "KayttoLiittyma.h"
#include <iostream>
#include <string>

int main() {
	
	std::wcout << L"\u2654" << L"\u2659" << std::endl;
	Asema* asema = new Asema();
	KayttoLiittyma kayttis(asema);
	kayttis.PiirraLauta();
	
	system("Pause");
	delete asema;
	return 0;
}