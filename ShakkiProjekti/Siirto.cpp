#include "Siirto.h"


//Lisäsin napin etumerkin että voi hyödyntää
Siirto::Siirto(Ruutu pos, Ruutu target, wchar_t nappi)
{

	napinEtumerkki = nappi;
	alkuRuutu = pos;
	loppuRuutu = target;
	lyhytLinna = false;
	pitkaLinna = false;

}

Siirto::Siirto(bool lyhytLinna, bool pitkaLinna, wchar_t nappi)
{
	napinEtumerkki = nappi;
	this->lyhytLinna = lyhytLinna;
	this->pitkaLinna = pitkaLinna;

}

Siirto::Siirto()
{
}


Siirto::~Siirto()
{
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
	return napinEtumerkki;
}

bool Siirto::HasNappi() {
	if (napinEtumerkki == '\0') {
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
