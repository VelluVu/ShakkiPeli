#pragma once
#include "Nappula.h"
class Torni :
	public virtual Nappula
{
public:

	virtual void AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari);
	Torni(std::wstring uni, int col, int code) : Nappula(uni,col,code) {};
	//virtual bool GetOnkoLiikkunut();
	//virtual void SetOnkoLiikkunut(bool liikkunut);
};

