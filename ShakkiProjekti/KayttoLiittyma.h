#pragma once
#include "Asema.h"
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <string>
#define WHITE 15
#define GREEN 2

class KayttoLiittyma
{
public:
	KayttoLiittyma(Asema* asema);
	~KayttoLiittyma();
	Asema* asema;
	void PiirraLauta();	
};

