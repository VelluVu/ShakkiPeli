#include "Siirto.h"


//Lis�sin napin etumerkin ett� voi hy�dynt��
Siirto::Siirto(Ruutu pos, Ruutu target, wchar_t nappi)
{

	_nappi = nappi;
	alkuRuutu = pos;
	loppuRuutu = target;
	lyhytLinna = false;
	pitkaLinna = false;

}

Siirto::Siirto(bool lyhytLinna, bool pitkaLinna, wchar_t nappi)
{
	_nappi = nappi;
	this->lyhytLinna = lyhytLinna;
	this->pitkaLinna = pitkaLinna;

}

Siirto::Siirto()
{
}


Siirto::~Siirto()
{
}

void Siirto::TulostaRuudut()
{
	std::wcout << "< Napin etumerkki=" << _nappi << " > < x=" << alkuRuutu.GetSarake() << " > < y=" << alkuRuutu.GetRivi() << " > < tx=" <<loppuRuutu.GetSarake() << " > < ty=" << loppuRuutu.GetRivi() << " >" << std::endl;
}

Ruutu Siirto::GetAlkuRuutu()
{
	return alkuRuutu;
}

Ruutu Siirto::GetLoppuRuutu()
{
	return loppuRuutu;
}

wchar_t Siirto::GetNappi()
{
	return _nappi;
}

bool Siirto::HasNappi() {
	if (_nappi == '\0') {
		return false;
	}
	return true;
}

bool Siirto::OnkoLyhytLinna()
{
	if (lyhytLinna) {
		return true;
	}
	else {
		return false;
	}
}

bool Siirto::OnkoPitkaLinna()
{
	if (pitkaLinna) {
		return true;
	}
	else {
		return false;
	}
}
