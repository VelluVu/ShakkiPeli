#pragma once
#include "Nappula.h"
class Torni :
	public Nappula
{
public:

	void AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari);
	Torni(std::wstring uni, int col, int code) : Nappula(uni,col,code) {};
};

