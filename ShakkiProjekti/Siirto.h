#pragma once
#include "Ruutu.h"
#include <iostream>

class Siirto
{
private:
	Ruutu alkuRuutu;
	Ruutu loppuRuutu;
	wchar_t _nappi;
	int miksiKorotetaan = 0;
	bool lyhytLinna;
	bool pitkaLinna;
	wchar_t siirtoT[5];

public:
	Siirto(Ruutu pos, Ruutu target, wchar_t nappi);
	Siirto(bool lyhytLinna, bool pitkaLinna, wchar_t nappi);
	Siirto();
	~Siirto();
	void TulostaRuudut();
	wchar_t* GetSiirto();
	Ruutu GetAlkuRuutu();
	Ruutu GetLoppuRuutu();
	bool HasNappi();
	wchar_t GetNappi();
	bool OnkoLyhytLinna();
	bool OnkoPitkaLinna();
	bool operator==(const Siirto& siirto) const
	{		

		if (&siirto != nullptr && siirtoT == siirto.siirtoT) {
			return true;
		}
		return false;
	}
};

