#include "Asema.h"

Asema::Asema()
{
	//nollaa ylimääräinen 'tauhka'
	for (size_t x = 0; x < 8; x++)
	{
		for (size_t y = 0; y < 8; y++)
		{
			lauta[x][y] = nullptr;
		}
	}

	//Alusta valkoiset nappulat
	for (size_t i = 0; i < 8; i++)
	{
		lauta[6][i] = new Nappula(L"\u2659", 0, VS);
	}

	lauta[7][0] = new Nappula(L"\u2656", 0, VT);
	lauta[7][1] = new Nappula(L"\u2658", 0, VR);
	lauta[7][2] = new Nappula(L"\u2657", 0, VL);
	lauta[7][3] = new Nappula(L"\u2655", 0, VD);
	lauta[7][4] = new Nappula(L"\u2654", 0, VK);
	lauta[7][5] = new Nappula(L"\u2656", 0, VT);
	lauta[7][6] = new Nappula(L"\u2658", 0, VR);
	lauta[7][7] = new Nappula(L"\u2656", 0, VT);

	//Alusta mustat nappulat
	for (size_t i = 0; i < 8; i++)
	{
		lauta[1][i] = new Nappula(L"\u265F", 1, MS);
	}

	lauta[0][0] = new Nappula(L"\u265C", 1, MT);
	lauta[0][1] = new Nappula(L"\u265E", 1, MR);
	lauta[0][2] = new Nappula(L"\u265D", 1, ML);
	lauta[0][3] = new Nappula(L"\u265B", 1, MD);
	lauta[0][4] = new Nappula(L"\u265A", 1, MK);
	lauta[0][5] = new Nappula(L"\u265D", 1, ML);
	lauta[0][6] = new Nappula(L"\u265E", 1, MR);
	lauta[0][7] = new Nappula(L"\u265C", 1, MT);


	//vanha malli...

	//alusta valkoiset nappulat
	
	/*vs = new Nappula(L"\u2659", 0, VS);
	vt = new Nappula(L"\u2656", 0, VT);
	vr = new Nappula(L"\u2658", 0, VR);
	vl = new Nappula(L"\u2657", 0, VL);
	vk = new Nappula(L"\u2654", 0 ,VK);
	vd = new Nappula(L"\u2655", 0 ,VD);

	//Aseta ne Asemaan
	for (size_t i = 0; i < 8; i++)
	{
		lauta[i][1] = vs;
	}
	
	lauta[0][0] = vt;
	lauta[1][0] = vr;
	lauta[2][0] = vl;
	lauta[3][0] = vk;
	lauta[4][0] = vd;
	lauta[5][0] = vl;
	lauta[6][0] = vr;
	lauta[7][0] = vt;

	//alusta mustat nappulat
	
	ms = new Nappula(L"\u265F", 1, MS);
	mt = new Nappula(L"\u265C", 1, MT);
	mr = new Nappula(L"\u265E", 1, MR);
	ml = new Nappula(L"\u265D", 1, ML);
	mk = new Nappula(L"\u265A", 1, MK);
	md = new Nappula(L"\u265B", 1, MD);

	//Aseta ne Asemaan
	for (size_t i = 0; i < 8; i++)
	{
		lauta[i][6] = ms;
	}
	lauta[0][7] = mt;
	lauta[1][7] = mr;
	lauta[2][7] = ml;
	lauta[4][7] = mk;
	lauta[3][7] = md;
	lauta[5][7] = ml;
	lauta[6][7] = mr;
	lauta[7][7] = mt;*/
	
}


Asema::~Asema()
{

	//Vanha malli

	//Tyhjää kaikki muistipaikat
	/*delete mk, md, vk, vd;
	mk, md, vk, vd = 0;
	
	delete vt, vr, vl, mt, mr, ml;
	vt, vr, vl, mt, mr, ml = 0;
	
	delete vs, ms;
	vs, ms = 0;*/
	

	// Tyhjää paikat ja nullaa...
	for (size_t x = 0; x < 8; x++)
	{
		for (size_t y = 0; y < 8; y++)
		{
			delete lauta[x][y];
			lauta[x][y] = nullptr;
		}
	}
	
}

void Asema::PaivitaAsema(Siirto* siirto)
{
	//Näin pääset siirtoon ja ruutuihin käsiksi...
	//std::wcout << siirto->GetAlkuRuutu().GetRivi() << siirto->GetAlkuRuutu().GetSarake() << std::endl;

	//Testaa minkä napin siirto on kyseessä
	switch (siirto->GetNappi())
	{
	case 'K':
		std::wcout << "Valitsit Kuninkaan" << std::endl;
		break;
	case 'D':
		std::wcout << "Valitsit Daamin" << std::endl;
		break;
	case 'L':
		std::wcout << "Valitsit Lähetin" << std::endl;
		break;
	case 'R':
		std::wcout << "Valitsit Ratsun" << std::endl;
		break;
	case 'T':
		std::wcout << "Valitsit Tornin" << std::endl;
		break;
	case 'S':
		std::wcout << "Valitsit Sotilaan" << std::endl;
		break;
	default:
		std::wcout << "Valitsit jonkun random, en tiiä..." << std::endl;
		break;
	}


}

int Asema::GetSiirtovuoro()
{
	return siirtovuoro;
}

void Asema::SetSiirtovuoro(int vari)
{
	siirtovuoro = vari;
}

bool Asema::GetOnkoValkeaKuningasLiikkunut()
{
	if (OnkoValkeaKuningasLiikkunut) {
		return true;
	}
	return false;
}

bool Asema::GetOnkoMustaKuningasLiikkunut()
{
	if (OnkoMustaKuningasLiikkunut) {
		return true;
	}
	return false;
}

bool Asema::GetOnkoValkeaDTliikkunut()
{
	if (OnkoValkeaDTLiikkunut) {
		return true;
	}
	return false;
}

bool Asema::GetOnkoValkeaKTliikkunut()
{
	if (OnkoValkeaKTLiikkunut) {
		return true;
	}
	return false;
}

bool Asema::GetOnkoMustaDTliikkunut()
{
	if (OnkoMustaDTLiikkunut) {
		return true;
	}
	return false;
}

bool Asema::GetOnkoMustaKTliikkunut()
{
	if (OnkoMustaKTLiikkunut) {
		return true;
	}
	return false;
}
