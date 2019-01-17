#pragma once
#include "Nappula.h"

class Asema
{
public:
	
	//Konstruktori luo alkuaseman laudalle
	Asema();
	~Asema();
	Nappula* lauta[8][8];
	Nappula* vs[7];
	Nappula* vt[1];
	Nappula* vr[1];
	Nappula* vl[1];
	Nappula* vk;
	Nappula* vd;

	Nappula* ms[7];
	Nappula* mt[1];
	Nappula* mr[1];
	Nappula* ml[1];
	Nappula* mk;
	Nappula* md;
};

