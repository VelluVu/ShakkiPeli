#include "KayttoLiittyma.h"
#include <string>

KayttoLiittyma::KayttoLiittyma(Asema * asema)
{
	this->asema = asema;
}

KayttoLiittyma::~KayttoLiittyma()
{
	delete asema;
	asema = 0;
}

void KayttoLiittyma::PiirraLauta()
{
	_setmode(_fileno(stdout), _O_U16TEXT);

	for (size_t x = 0; x < 8; x++)
	{
		for (size_t y = 0; y < 8; y++)
		{
			if (x % 2 == 0  &&  y % 2 == 0) {
				std::cout << "0";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else {
				std::cout << "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
				BACKGROUND_GREEN | BACKGROUND_BLUE);
			}
			//std::wcout << asema->lauta[x][y]->getUnicode();
		}
		std::cout << std::endl;
	}
}