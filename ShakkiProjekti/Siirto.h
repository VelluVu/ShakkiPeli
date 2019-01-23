#pragma once
#include "Ruutu.h"

class Siirto
{
private:
	Ruutu alkuRuutu;
	Ruutu loppuRuutu;
	int miksiKorotetaan = 0;
	bool lyhytLinna;
	bool pitkaLinna;

public:
	Siirto(Ruutu pos, Ruutu target);
	Siirto(bool lyhytLinna, bool pitkaLinna);
	Siirto();
	~Siirto();
	Ruutu GetAlkuRuutu();
	Ruutu GetLoppuRuutu();
	bool OnkoLyhytLinna();
	bool OnkoPitkaLinna();
};

