#include "Siirto.h"


//Lis�sin napin etumerkin ett� voi hy�dynt��
Siirto::Siirto(Ruutu pos, Ruutu target)
{

	_alkuRuutu = pos;
	_loppuRuutu = target;
	_lyhytLinna = false;
	_pitkaLinna = false;
	_viereenHutasu = false;
}

Siirto::Siirto(bool lyhytLinna, bool pitkaLinna)
{

	_lyhytLinna = lyhytLinna;
	_pitkaLinna = pitkaLinna;
	_alkuRuutu = Ruutu(0, 0);
	_loppuRuutu = Ruutu(0, 0);
	_viereenHutasu = false;
}

Siirto::Siirto(Ruutu pos, Ruutu target, bool viereen)
{

	_alkuRuutu = pos;
	_loppuRuutu = target;
	_lyhytLinna = false;
	_pitkaLinna = false;
	_viereenHutasu = viereen;
}

void Siirto::TulostaRuudut()
{
	wchar_t x = 'a';
	wchar_t tx = 'a';
	if (_alkuRuutu.GetSarake() == 0)
		x = 'a';
	if (_loppuRuutu.GetSarake() == 0)
		tx = 'a';
	if (_alkuRuutu.GetSarake() == 1)
		x = 'b'; 
	if (_loppuRuutu.GetSarake() == 1) 
		tx = 'b';
	if (_alkuRuutu.GetSarake() == 2)
		x = 'c'; 
	if (_loppuRuutu.GetSarake() == 2)
		tx = 'c';
	if (_alkuRuutu.GetSarake() == 3)
		x = 'd'; 
	if (_loppuRuutu.GetSarake() == 3)
		tx = 'd';
	if (_alkuRuutu.GetSarake() == 4)
		x = 'e'; 
	if (_loppuRuutu.GetSarake() == 4)
		tx = 'e';
	if (_alkuRuutu.GetSarake() == 5)
		x = 'f'; 
	if (_loppuRuutu.GetSarake() == 5)
		tx = 'f';
	if (_alkuRuutu.GetSarake() == 6) 
		x = 'g'; 
	if (_loppuRuutu.GetSarake() == 6)
		tx = 'g';
	if (_alkuRuutu.GetSarake() == 7)
		x = 'h'; 
	if (_loppuRuutu.GetSarake() == 7)
		tx = 'h';

	std::wcout << x << _alkuRuutu.GetRivi()+1 << "-" << tx << _loppuRuutu.GetRivi() +1 << std::endl;
}

Ruutu Siirto::GetAlkuRuutu()
{
	return this->_alkuRuutu;
}

Ruutu Siirto::GetLoppuRuutu()
{
	return this->_loppuRuutu;
}

bool Siirto::OnkoLyhytLinna()
{
	if (this->_lyhytLinna == true) {
		return true;
	}
	else 
	{
		return false;
	}
}

bool Siirto::OnkoPitkaLinna()
{
	if (this->_pitkaLinna == true) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool Siirto::OnkoSotilaanViereenIsku()
{
	if (this->_viereenHutasu == true) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

