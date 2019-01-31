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

void Siirto::TulostaRuudut()
{
	int x1 = 0;
	int x2 = 0;
	for (int i = 0; i < 8; i++)
	{
		if (alkuRuutu.GetRivi() == i) {
			x1 = 7 - i;
		}
		if (loppuRuutu.GetRivi() == i) {
			x2 = 7 - i;
		}
	}
	std::wcout << x1 << alkuRuutu.GetSarake() << x2 << loppuRuutu.GetSarake() << std::endl;
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
