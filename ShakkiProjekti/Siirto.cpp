#include "Siirto.h"


//Lis�sin napin etumerkin ett� voi hy�dynt��
Siirto::Siirto(Ruutu pos, Ruutu target)
{

	alkuRuutu = pos;
	loppuRuutu = target;
	lyhytLinna = false;
	pitkaLinna = false;
	viereenHutasu = false;
}

Siirto::Siirto(bool lyhytLinna, bool pitkaLinnai)
{

	lyhytLinna = lyhytLinna;
	pitkaLinna = pitkaLinna;
	alkuRuutu = Ruutu(0, 0);
	loppuRuutu = Ruutu(0, 0);
	viereenHutasu = false;
}

Siirto::Siirto(Ruutu pos, Ruutu target, bool viereen)
{

	alkuRuutu = pos;
	loppuRuutu = target;
	lyhytLinna = false;
	pitkaLinna = false;
	viereenHutasu = viereen;
}

void Siirto::TulostaRuudut()
{
	wchar_t x = 'a';
	wchar_t tx = 'a';
	if (alkuRuutu.GetSarake() == 0)
		x = 'a';
	if (loppuRuutu.GetSarake() == 0)
		tx = 'a';
	if (alkuRuutu.GetSarake() == 1)
		x = 'b'; 
	if (loppuRuutu.GetSarake() == 1) 
		tx = 'b';
	if (alkuRuutu.GetSarake() == 2)
		x = 'c'; 
	if (loppuRuutu.GetSarake() == 2)
		tx = 'c';
	if (alkuRuutu.GetSarake() == 3)
		x = 'd'; 
	if (loppuRuutu.GetSarake() == 3)
		tx = 'd';
	if (alkuRuutu.GetSarake() == 4)
		x = 'e'; 
	if (loppuRuutu.GetSarake() == 4)
		tx = 'e';
	if (alkuRuutu.GetSarake() == 5)
		x = 'f'; 
	if (loppuRuutu.GetSarake() == 5)
		tx = 'f';
	if (alkuRuutu.GetSarake() == 6) 
		x = 'g'; 
	if (loppuRuutu.GetSarake() == 6)
		tx = 'g';
	if (alkuRuutu.GetSarake() == 7)
		x = 'h'; 
	if (loppuRuutu.GetSarake() == 7)
		tx = 'h';

	std::wcout << "( " << x << "," << alkuRuutu.GetRivi()+1 << " ) - ( " << tx << "," << loppuRuutu.GetRivi() +1 << " )" << std::endl;
}

Ruutu Siirto::GetAlkuRuutu()
{
	return alkuRuutu;
}

Ruutu Siirto::GetLoppuRuutu()
{
	return loppuRuutu;
}

bool Siirto::OnkoLyhytLinna()
{
	if (lyhytLinna == true) {
		return true;
	}
	else {
		return false;
	}
}

bool Siirto::OnkoPitkaLinna()
{
	if (pitkaLinna == true) {
		return true;
	}
	else {
		return false;
	}
}

bool Siirto::OnkoSotilaanViereenIsku()
{
	if (viereenHutasu == true) {
		return true;
	}
	else {
		return false;
	}
}

