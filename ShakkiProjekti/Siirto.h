#pragma once
#include "Ruutu.h"
#include <iostream>

class Nappula;

class Siirto
{
private:
	Ruutu alkuRuutu;
	Ruutu loppuRuutu;
	bool _lyhytLinna;
	bool _pitkaLinna;
	bool viereenHutasu;

public:
	double siirronArvo = 0;
	Siirto() {};
	Siirto(Ruutu pos, Ruutu target);
	Siirto(bool lyhytLinna, bool pitkaLinna);
	Siirto(Ruutu pos, Ruutu target, bool viereen);
	Nappula* miksiKorotetaan = 0;
	void TulostaRuudut();
	Ruutu GetAlkuRuutu();
	Ruutu GetLoppuRuutu();
	bool OnkoLyhytLinna();
	bool OnkoPitkaLinna();
	bool OnkoSotilaanViereenIsku();

	bool operator==(const Siirto& siirto)
	{		

		return this->alkuRuutu == siirto.alkuRuutu &&
			this->loppuRuutu == siirto.loppuRuutu &&
			this->_lyhytLinna == siirto._lyhytLinna && 
			this->_pitkaLinna == siirto._pitkaLinna &&
			this->viereenHutasu == siirto.viereenHutasu;
		
	}
};

