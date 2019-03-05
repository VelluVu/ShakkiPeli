#pragma once
#include "Asema.h"
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <string>
#include "Siirto.h"

class KayttoLiittyma
{
public:
	KayttoLiittyma(Asema* asema);
	Asema* asema;
	void PiirraLauta();	
	Siirto AnnaVastustajanSiirto();
};

