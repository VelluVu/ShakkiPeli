#pragma once
#include "Nappula.h"
class Lahetti :
	public virtual Nappula
{
public:

	virtual void AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari);
	Lahetti(std::wstring uni, int col, int code) : Nappula(uni, col, code) {};
	
};

