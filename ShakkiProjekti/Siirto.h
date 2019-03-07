#pragma once
#include "Ruutu.h"
#include <iostream>

class Nappula;

class Siirto
{
private:
	Ruutu alkuRuutu;
	Ruutu loppuRuutu;
	bool lyhytLinna;
	bool pitkaLinna;
	bool viereenHutasu;

public:
	Siirto(Ruutu pos, Ruutu target);
	Siirto(Ruutu pos, Ruutu target, bool viereen);
	Siirto() {};
	Siirto(bool lyhytLinna, bool pitkaLinna);
	Nappula* miksiKorotetaan = 0;
	void TulostaRuudut();
	Ruutu GetAlkuRuutu();
	Ruutu GetLoppuRuutu();
	bool OnkoLyhytLinna();
	bool OnkoPitkaLinna();
	bool OnkoSotilaanViereenIsku();
	bool operator==(const Siirto& siirto)
	{		

		return alkuRuutu == siirto.alkuRuutu && loppuRuutu == siirto.loppuRuutu &&
			lyhytLinna == siirto.lyhytLinna && pitkaLinna == siirto.pitkaLinna;
		
	}
};

