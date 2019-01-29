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
	Siirto(bool lyhytLinna, bool pitkaLinna, wchar_t nappi);
	Siirto();
	~Siirto();
	Ruutu GetAlkuRuutu();
	Ruutu GetLoppuRuutu();
	bool HasNappi();
	wchar_t GetNappi();
	bool OnkoLyhytLinna();
	bool OnkoPitkaLinna();
};

