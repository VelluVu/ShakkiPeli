#pragma once
#include "Nappula.h"
class Lahetti :
	public Nappula
{
public:

	void AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari);
	Lahetti(std::wstring uni, int col, int code) : Nappula(uni, col, code) {};
};

