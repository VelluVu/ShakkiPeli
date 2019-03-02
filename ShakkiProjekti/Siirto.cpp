#include "Siirto.h"


//Lis�sin napin etumerkin ett� voi hy�dynt��
Siirto::Siirto(Ruutu pos, Ruutu target, wchar_t nappi)
{

	_nappi = nappi;
	alkuRuutu = pos;
	loppuRuutu = target;
	lyhytLinna = false;
	pitkaLinna = false;

	siirtoT[0] = this->GetNappi();
	siirtoT[1] = this->GetAlkuRuutu().GetSarake();
	siirtoT[2] = this->GetAlkuRuutu().GetRivi();
	siirtoT[3] = this->GetLoppuRuutu().GetSarake();
	siirtoT[4] = this->GetLoppuRuutu().GetRivi();

}

Siirto::Siirto(bool lyhytLinna, bool pitkaLinna, wchar_t nappi)
{
	_nappi = nappi;
	this->lyhytLinna = lyhytLinna;
	this->pitkaLinna = pitkaLinna;
	this->alkuRuutu = Ruutu(0, 0);
	this->loppuRuutu = Ruutu(0, 0);

}

Siirto::Siirto()
{
}


Siirto::~Siirto()
{
}

void Siirto::TulostaRuudut()
{
	std::wcout << "<" << _nappi << "> (x;y) = (" << alkuRuutu.GetSarake() << ";" << alkuRuutu.GetRivi() << ") (tx;ty) = (" <<loppuRuutu.GetSarake() << ";" << loppuRuutu.GetRivi() << ")" << std::endl;
}

wchar_t* Siirto::GetSiirto()
{

	return siirtoT;

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
