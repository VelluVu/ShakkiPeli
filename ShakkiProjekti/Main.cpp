#include "KayttoLiittyma.h"
#include <iostream>
#include <string>

int main() {
	
	Asema* asema = new Asema();
	KayttoLiittyma kayttis(asema);
	kayttis.PiirraLauta();
	
	system("Pause");
	delete asema;
	return 0;
}