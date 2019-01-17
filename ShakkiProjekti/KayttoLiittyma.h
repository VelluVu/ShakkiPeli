#pragma once
#include "Asema.h"

class KayttoLiittyma
{
public:
	KayttoLiittyma(Asema* asema);
	~KayttoLiittyma();
	Asema* asema;
	void piirraLauta();	
};

