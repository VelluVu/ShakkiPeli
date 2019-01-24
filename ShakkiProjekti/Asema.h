#pragma once
#include "Nappula.h"
#include "Siirto.h"
#include <string>

class Asema
{
private:

	int siirtovuoro;
	bool OnkoValkeaKuningasLiikkunut;
	bool OnkoMustaKuningasLiikkunut;
	bool OnkoValkeaDTLiikkunut;
	bool OnkoValkeaKTLiikkunut;
	bool OnkoMustaDTLiikkunut;
	bool OnkoMustaKTLiikkunut;

public:
	
	//Konstruktori luo alkuaseman laudalle
	Asema();
	~Asema();

	//jäsenmuuttujaosoitinlistaa hyödyntäen?
	Nappula* lauta[8][8];

	//vai jäsenmuuttujat muuttujat erikseen listasta osoittimina?
	/*Nappula* vs;
	Nappula* vt;
	Nappula* vr;
	Nappula* vl;
	Nappula* vk;
	Nappula* vd;

	Nappula* ms;
	Nappula* mt;
	Nappula* mr;
	Nappula* ml;
	Nappula* mk;
	Nappula* md;*/

	void PaivitaAsema(Siirto* siirto);
	int GetSiirtovuoro();
	void SetSiirtovuoro(int vari);
	bool GetOnkoValkeaKuningasLiikkunut();
	bool GetOnkoMustaKuningasLiikkunut();
	bool GetOnkoValkeaDTliikkunut();
	bool GetOnkoValkeaKTliikkunut();
	bool GetOnkoMustaDTliikkunut();
	bool GetOnkoMustaKTliikkunut();

};

