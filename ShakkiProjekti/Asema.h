#pragma once
#include "Nappula.h"
#include <string>

class Asema
{
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
};

