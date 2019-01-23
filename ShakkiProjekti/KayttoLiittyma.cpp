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

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		std::wcout << 8 - x;

		for (int y = 0; y < 8; y++)
		{

			if ((x + y) % 2 == 0) {

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			}
			else {

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  BACKGROUND_GREEN | BACKGROUND_RED);


			}
			if (asema->lauta[x][y] != nullptr) {
				std::wcout << asema->lauta[x][y]->GetUnicode();
			}
			else {
				std::wcout << " ";
			}
		}
		std::wcout << std::endl;
	}
	
	std::wcout << " ";
	char arr[] = { 'a','b','c','d','e','f','g','h' };
	for (size_t i = 0; i < 8; i++)
	{
		std::wcout << arr[i];
	}
	
	std::wcout << std::endl << std::endl;
}

Siirto KayttoLiittyma::AnnaVastustajanSiirto()
{
	
	std::wcout << "Anna siirto muodossa: (Napin etumerkki/Alkukoordinaatti/Loppukoordinaatti)" << std::endl;
	
	Siirto siirto = new Siirto();
	return Siirto();
}
