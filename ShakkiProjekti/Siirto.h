#pragma once
#include "Ruutu.h"
#include <iostream>

class Nappula;

class Siirto
{
private:
	Ruutu _alkuRuutu;
	Ruutu _loppuRuutu;
	bool _lyhytLinna;
	bool _pitkaLinna;
	bool _viereenHutasu;

public:
	double siirronArvo = 0;
	Siirto() {
		_lyhytLinna = false;
		_pitkaLinna = false;
		_viereenHutasu = false;
		_alkuRuutu = Ruutu(0, 0);
		_loppuRuutu = Ruutu(0, 0);
	};
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

		return _alkuRuutu == siirto._alkuRuutu &&
		_loppuRuutu == siirto._loppuRuutu &&
		_lyhytLinna == siirto._lyhytLinna && 
		_pitkaLinna == siirto._pitkaLinna &&
		_viereenHutasu == siirto._viereenHutasu;
		
	}

};

