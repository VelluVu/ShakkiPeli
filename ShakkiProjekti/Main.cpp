#include "KayttoLiittyma.h"
#include <iostream>
using namespace std;

int main() {

	wcout << L"\u2654" << L"\u2659" << endl;
	Asema* asema = new Asema();
	KayttoLiittyma kayttis(asema);
	kayttis.PiirraLauta();
	
	system("Pause");
	delete asema;
	return 0;
}