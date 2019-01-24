#include "Siirto.h"


//Lisäsin napin etumerkin että voi hyödyntää
Siirto::Siirto(Ruutu pos, Ruutu target, wchar_t nappi)
{

	napinEtumerkki = nappi;
	alkuRuutu = pos;
	loppuRuutu = target;

}

Siirto::Siirto(bool lyhytLinna, bool pitkaLinna)
{

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

bool Siirto::OnkoLyhytLinna()
{
	if (lyhytLinna) {
		return true;
	}
	return false;
}

bool Siirto::OnkoPitkaLinna()
{
	if (pitkaLinna) {
		return true;
	}
	return false;
}
