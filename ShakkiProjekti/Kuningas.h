#pragma once
#include "Nappula.h"
class Kuningas :
	public Nappula
{
public:

	void AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari);
	Kuningas(std::wstring uni, int col, int code) : Nappula(uni,col,code) {};
};

