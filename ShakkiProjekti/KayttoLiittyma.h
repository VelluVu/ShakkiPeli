#pragma once
#include "Asema.h"
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <string>
#include "Siirto.h"
#include <vector>

class KayttoLiittyma
{
public:
	KayttoLiittyma(Asema* asema);
	void PiirraLauta();	
	Siirto AnnaVastustajanSiirto();

private:
	Asema* asema;
};

