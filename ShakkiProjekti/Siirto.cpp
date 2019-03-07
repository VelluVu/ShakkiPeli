#include "Siirto.h"


//Lis�sin napin etumerkin ett� voi hy�dynt��
Siirto::Siirto(Ruutu pos, Ruutu target)
{

	alkuRuutu = pos;
	loppuRuutu = target;
	lyhytLinna = false;
	pitkaLinna = false;
	this->viereenHutasu = false;
}

Siirto::Siirto(Ruutu pos, Ruutu target, bool viereen)
{

	alkuRuutu = pos;
	loppuRuutu = target;
	lyhytLinna = false;
	pitkaLinna = false;
	this->viereenHutasu = viereen;
}

Siirto::Siirto(bool lyhytLinna, bool pitkaLinnai)
{

	this->lyhytLinna = lyhytLinna;
	this->pitkaLinna = pitkaLinna;
	this->alkuRuutu = Ruutu(0, 0);
	this->loppuRuutu = Ruutu(0, 0);
	this->viereenHutasu = false;
}

void Siirto::TulostaRuudut()
{
	std::wcout << "(x;y) = (" << alkuRuutu.GetSarake() << ";" << alkuRuutu.GetRivi() << ") (tx;ty) = (" <<loppuRuutu.GetSarake() << ";" << loppuRuutu.GetRivi() << ")" << std::endl;
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

bool Siirto::OnkoSotilaanViereenIsku()
{
	if (viereenHutasu) {
		return true;
	}
	else {
		return false;
	}
}
