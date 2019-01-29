#pragma once
#include "Nappula.h"

class Sotilas :
	public Nappula
{
public:
	void AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari);
	Sotilas(std::wstring uni, int col, int code) : Nappula(uni, col, code) {};
};
