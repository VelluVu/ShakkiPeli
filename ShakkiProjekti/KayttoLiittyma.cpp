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

		for (int y = 0; y < 8 ; y++)
		{

			if ((x+y) % 2 == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  BACKGROUND_GREEN | BACKGROUND_RED);
			}
			
			if (asema->lauta[x][y] != nullptr) {
				std::wcout << " " << asema->lauta[x][y]->GetUnicode() << " ";
			}
			else {
				std::wcout << "   ";
			}
		}
		std::wcout << std::endl;
	}
	
	std::wcout << " ";
	char arr[] = { 'a','b','c','d','e','f','g','h' };
	for (size_t i = 0; i < 8; i++)
	{
		std::wcout  << " " << arr[i] << " ";
	}
	
	std::wcout << std::endl << std::endl;
}

Siirto KayttoLiittyma::AnnaVastustajanSiirto()
{
	//== vertausta varten 2 array
	char arr[] = { 'a','b','c','d','e','f','g','h' };
	int arrn[] = { '1','2','3','4','5','6','7','8' };
	//Tähän tallennetaan koko siirto
	std::wstring siirto;
	//puretaan wstring siirto[] näihin kirjaimiin
	wchar_t startCoord1Input = 0, startCoord2Input = 0, endCoord1Input = 0, endCoord2Input = 0;
	//mapataan kirjaimien paikkakoordinaattiarvot näihin muuttujiin
	int startCoord1 = 0, startCoord2 = 0, endCoord1 = 0, endCoord2 = 0;
	//nappulan etumerkki
	wchar_t nappi;

	std::wcout << "Anna siirto muodossa: (Napin etumerkki<T/R/L/D/K/S> / Alkukoordinaatti<'char',int> / Loppukoordinaatti<'char',int>)" << std::endl;
	std::wcin >> siirto;
	
	nappi = siirto[0];
	startCoord1Input = siirto[1];
	startCoord2Input = siirto[2];

	if (siirto.length() > 3) {
		endCoord1Input = siirto[3];
		endCoord2Input = siirto[4];
	}
	
	std::wcout << nappi << startCoord1Input << startCoord2Input << "-" << endCoord1Input << endCoord2Input << std::endl;
	
	//Vertaa inputdataa arrayn indexissä olevaan arvoon ja aseta indexi koordinaatin arvoksi
	for (int i = 0; i < 8; i++)
	{
		if (arr[i] == startCoord1Input) {
			startCoord1 = i;
		}
		//koska 00 on vasenyläkulma, mutta halutaan vasen alakulma
		if (arrn[i] == startCoord2Input) {
			startCoord2 = 7 - i;
		}

		if (arr[i] == endCoord1Input) {
			endCoord1 = i;
		}

		//koska 00 on vasenyläkulma, mutta halutaan vasen alakulma
		if (arrn[i] == endCoord2Input) {
			endCoord2 = 7 - i;
		}
	}
	
	//Testaa onko lyhytlinna vai pitkälinna
	if (startCoord1Input == 'O' && startCoord2Input == 'O' && endCoord1Input == 0 && endCoord2Input == 0) {
		Siirto lyhytLinna(true, false, nappi);
		std::wcout << "LyhytLinna" << std::endl;
		return lyhytLinna;
	}
	if (startCoord1Input == 'O' && startCoord2Input == 'O' && endCoord1Input == 'O' && endCoord2Input == 0) {
		Siirto pitkaLinna(false, true, nappi);
		std::wcout << "PitkäLinna" << std::endl;
		return pitkaLinna;
	}
	//Testaa onko sotilas viimesellä rivillä
	if (startCoord2 == 6 && endCoord2 == 7 || startCoord2 == 1 && endCoord2 == 0) {
		//Korota sotilas...
		std::wcout << "Korota sotilas" << std::endl;
		 
	}
	if (startCoord2 == 1 && endCoord2 == 3 || startCoord2 == 6 && endCoord2 == 4) {
		//Sotilas liikkuu 2 ruutua
		std::wcout << "Sotilas liikkuu 2 ruutua" << std::endl;

	}

	Ruutu alku(startCoord1, startCoord2);
	Ruutu end(endCoord1, endCoord2);
	Siirto move(alku, end, nappi);

	return move;
}
