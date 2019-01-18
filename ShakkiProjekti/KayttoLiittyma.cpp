#include "KayttoLiittyma.h"
#include <Windows.h>


KayttoLiittyma::KayttoLiittyma(Asema * asema)
{
	this->asema = asema;
	PiirraLauta();
}

KayttoLiittyma::~KayttoLiittyma()
{
	delete asema;
	asema = 0;
}

void KayttoLiittyma::PiirraLauta()
{

	for (size_t x = 0; x < 8; x++)
	{
		for (size_t y = 0; y< 8; y++)
		{
			if (x % 2 == 0 && y % 2 == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
					BACKGROUND_GREEN | BACKGROUND_BLUE);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			}
		}
	}
}