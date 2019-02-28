#pragma once
#include "Ruutu.h"
#include <iostream>

class Nappula;

class Siirto
{
private:
	Ruutu alkuRuutu;
	Ruutu loppuRuutu;
	wchar_t _nappi;
	bool lyhytLinna;
	bool pitkaLinna;
	wchar_t siirtoT[5];

public:
	Siirto(Ruutu pos, Ruutu target, wchar_t nappi);
	Siirto(bool lyhytLinna, bool pitkaLinna, wchar_t nappi);
	Siirto();
	~Siirto();
	Nappula* miksiKorotetaan = 0;
	void TulostaRuudut();
	wchar_t* GetSiirto();
	Ruutu GetAlkuRuutu();
	Ruutu GetLoppuRuutu();
	bool HasNappi();
	wchar_t GetNappi();
	bool OnkoLyhytLinna();
	bool OnkoPitkaLinna();
	bool operator==(const Siirto& siirto)
	{		

		return alkuRuutu == siirto.alkuRuutu && loppuRuutu == siirto.loppuRuutu &&
			lyhytLinna == siirto.lyhytLinna && pitkaLinna == siirto.pitkaLinna;
		
	}
};

