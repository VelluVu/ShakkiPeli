#include "Siirto.h"



Siirto::Siirto(Ruutu pos, Ruutu target)
{
	
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
