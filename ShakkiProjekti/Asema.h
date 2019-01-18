#pragma once
#include "Nappula.h"

class Asema
{
public:
	
	//Konstruktori luo alkuaseman laudalle
	Asema();
	~Asema();
	Nappula* lauta[8][8];
	Nappula* vs;
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
	Nappula* md;
};

