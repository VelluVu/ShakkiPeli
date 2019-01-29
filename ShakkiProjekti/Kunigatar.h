#pragma once
#include "Nappula.h"
#include "Lahetti.h"
#include "Torni.h"

class Kuningatar : 
	public Nappula
{
public:

	void AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari);
	Kuningatar(std::wstring uni, int col, int code) : Nappula(uni,col,code) {};
};

