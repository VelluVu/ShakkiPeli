#pragma once
#include "Asema.h"
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <string>

class KayttoLiittyma
{
public:
	KayttoLiittyma(Asema* asema);
	~KayttoLiittyma();
	Asema* asema;
	void PiirraLauta();	
};

