#pragma once
#include "Ruutu.h"

class Siirto
{
private:
	Ruutu alkuRuutu;
	Ruutu loppuRuutu;
	wchar_t napinEtumerkki;
	int miksiKorotetaan = 0;
	bool lyhytLinna;
	bool pitkaLinna;

public:
	Siirto(Ruutu pos, Ruutu target, wchar_t nappi);
	Siirto(bool lyhytLinna, bool pitkaLinna);
	Siirto();
	~Siirto();
	Ruutu GetAlkuRuutu();
	Ruutu GetLoppuRuutu();
	wchar_t GetNappi();
	bool OnkoLyhytLinna();
	bool OnkoPitkaLinna();
};

