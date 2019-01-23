#include "Siirto.h"



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
