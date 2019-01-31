#pragma once
#include "Nappula.h"
#include "Siirto.h"
#include <string>
#include "Sotilas.h"
#include "Torni.h"
#include "Ratsu.h"
#include "Lahetti.h"
#include "Kuningas.h"
#include "Kunigatar.h"

class Asema
{
private:

	int siirtovuoro;
	bool onkoValkeaKuningasLiikkunut;
	bool onkoMustaKuningasLiikkunut;
	bool onkoValkeaDTLiikkunut;
	bool onkoValkeaKTLiikkunut;
	bool onkoMustaDTLiikkunut;
	bool onkoMustaKTLiikkunut;

public:
	
	//Konstruktori luo alkuaseman laudalle
	Asema();
	~Asema();

	//Lauta [rivi] [sarake]
	Nappula* lauta[8][8];

	Sotilas* vs;
	Torni* vt;
	Ratsu* vr;
	Lahetti* vl;
	Kuningas* vk;
	Kuningatar* vd;

	Sotilas* ms;
	Torni* mt;
	Ratsu* mr;
	Lahetti* ml;
	Kuningas* mk;
	Kuningatar* md;
	
	

	void PaivitaAsema(Siirto* siirto);
	int GetSiirtovuoro();
	void SetSiirtovuoro(int vari);
	void AnnaLaillisetSiirrot(std::list<Siirto>& lista);
	bool GetOnkoValkeaKuningasLiikkunut();
	bool GetOnkoMustaKuningasLiikkunut();
	bool GetOnkoValkeaDTliikkunut();
	bool GetOnkoValkeaKTliikkunut();
	bool GetOnkoMustaDTliikkunut();
	bool GetOnkoMustaKTliikkunut();

};

