#include "KayttoLiittyma.h"

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

	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			if (x % 2 == 0 && y % 2 == 0) {
				std::wcout << "0";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			}
			else {
				std::wcout << "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
					BACKGROUND_GREEN | BACKGROUND_BLUE);
			}
			if (asema->lauta[x][y] != nullptr) {
				std::wcout << asema->lauta[x][y]->getUnicode();
			}
		}
		std::wcout << std::endl;
	}
}