#include "KayttoLiittyma.h"


KayttoLiittyma::KayttoLiittyma(Asema * asema)
{
	this->asema = asema;
}

void KayttoLiittyma::PiirraLauta()
{

	_setmode(_fileno(stdout), _O_U16TEXT);

	for (int y = 7; y >= 0; y--)
	{

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		std::wcout << y +1;
		

		for (int x = 0; x < 8 ; x++)
		{

			if ((x+y) % 2 == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_RED);
			}
			else {
				
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
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
	
	int lahtoX;
	int lahtoY;
	int tuloX;
	int tuloY;
	std::wstring siirtoString;
	std::wstring siirtynytNappulaString;

	
		std::wcout << "Anna siirtosi esim. (esim. Rg1-f3, linnoitus 0-0 tai 0-0-0)\n";
		std::wcin >> siirtoString;
		if (siirtoString == L"0-0" || siirtoString == L"0-0-0") {
			if (siirtoString == L"0-0") {
				return Siirto(true, false);
			}
			if (siirtoString == L"0-0-0") {
				return Siirto(false, true);
			}
		}
		else if (siirtoString.length() == 6) {
			siirtynytNappulaString = siirtoString[0];
			siirtoString.erase(0, 1);
		}
		else {
			siirtynytNappulaString = L"s";
		}
		lahtoX = siirtoString[0] - 'a';
		lahtoY = siirtoString[1] - '1';
		tuloX = siirtoString[3] - 'a';
		tuloY = siirtoString[4] - '1';

	
	Ruutu lahtoRuutu(lahtoX, lahtoY);
	Ruutu tuloRuutu(tuloX, tuloY);
	Siirto siirto(lahtoRuutu, tuloRuutu);

	//Testaa onko sotilas viimesellä rivillä
	if (siirtynytNappulaString == L"s" && (tuloY == 7 || tuloY == 0))
	{

		wchar_t korotettuNappula;

		//Korota sotilas...
		std::wcout << "Korota sotilas (D/T/L/R)" << std::endl;
		std::wcin >> korotettuNappula;
		if (tuloY == 7) 
		{
			switch (korotettuNappula)
			{
			case 'D':
				siirto.miksiKorotetaan = asema->vd;
				break;

			case 'T':
				siirto.miksiKorotetaan = asema->vt;
				break;

			case 'L':
				siirto.miksiKorotetaan = asema->vl;
				break;

			case 'R':
				siirto.miksiKorotetaan = asema->vr;
				break;

			default:
				break;
			}
		} 
		if (tuloY == 0) 
		{
			switch (korotettuNappula)
			{
			case 'D':
				siirto.miksiKorotetaan = asema->md;
				break;

			case 'T':
				siirto.miksiKorotetaan = asema->mt;
				break;

			case 'L':
				siirto.miksiKorotetaan = asema->ml;
				break;

			case 'R':
				siirto.miksiKorotetaan = asema->mr;
				break;

			default:
				break;
			}
		}
	}

	return siirto;

	////== vertausta varten 2 array, toimii mutta ottaa input etumerkin sotilaalle eikä tarvi "-"
	//char arr[] = { 'a','b','c','d','e','f','g','h' };
	//int arrn[] = { '1','2','3','4','5','6','7','8' };
	////Tähän tallennetaan koko siirto
	//std::wstring siirto;
	////puretaan wstring siirto[] eli inputti näihin input muuttujiin
	//wchar_t xInput = 0, yInput = 0, txInput = 0, tyInput = 0;
	////mapataan input muuttujien paikkakoordinaattiarvot näihin kokonaisluku muuttujiin , alku x = sarake ja alku y = rivi, tx = target x ja ty = target y
	//int x = 0, y = 0, tx = 0, ty = 0;
	////nappulan etumerkki
	//wchar_t nappi;

	//std::wcout << "Anna siirto muodossa: (Napin etumerkki<T/R/L/D/K/S> / Alkukoordinaatti<'char',int> / Loppukoordinaatti<'char',int>)" << std::endl;
	//std::wcin >> siirto;

	//nappi = siirto[0];
	//xInput = siirto[1];
	//yInput = siirto[2];

	//if (siirto.length() > 3) {
	//	txInput = siirto[3];
	//	tyInput = siirto[4];
	//}

	////Vertaa inputdataa arrayn indexissä olevaan arvoon ja aseta indexi koordinaatin arvoksi
	//for (int i = 0; i < 8; i++)
	//{
	//	if (arr[i] == xInput) {
	//		x = i;
	//		//std::wcout << "x : " << x << std::endl;
	//	}
	//}
	//for (int i = 0; i < 8; i++)
	//{
	//	if (arrn[i] == yInput) {
	//		y = i;
	//		//std::wcout << "y : " << y << std::endl;
	//	}
	//}
	//for (int i = 0; i < 8; i++)
	//{
	//	if (arr[i] == txInput) {
	//		tx = i;
	//		//std::wcout << "target x : " << tx << std::endl;
	//	}
	//}
	//for (int i = 0; i < 8; i++)
	//{
	//	if (arrn[i] == tyInput) {
	//		ty = i;
	//		//std::wcout << "target y : " << ty << std::endl;
	//	}
	//}

	////Testaa onko lyhytlinna vai pitkälinna
	//if (xInput == 'O' && yInput == 'O' && txInput == 0 && tyInput == 0) {
	//	Siirto lyhytLinna(true, false, nappi);
	//	std::wcout << "LyhytLinna" << std::endl;
	//	return lyhytLinna;
	//}
	//if (xInput == 'O' && yInput == 'O' && txInput == 'O' && tyInput == 0) {
	//	Siirto pitkaLinna(false, true, nappi);
	//	std::wcout << "PitkäLinna" << std::endl;
	//	return pitkaLinna;
	//}
	//
	//if (y == 1 && ty == 3 || y == 6 && ty == 4) {
	//	//Sotilas liikkuu 2 ruutua
	//	std::wcout << "Sotilas liikkuu 2 ruutua" << std::endl;
	//}

	//Ruutu alku(x, y);
	//Ruutu end(tx, ty);
	//Siirto move(alku, end, nappi);
}
