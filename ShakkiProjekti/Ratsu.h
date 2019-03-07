#pragma once
#include "Nappula.h"
class Ratsu :
	public Nappula
{
public:

	void AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari);
	Ratsu(std::wstring uni, int col, int code) : Nappula(uni, col, code) {};
	double arvo = 3.0;
	//bool GetOnkoLiikkunut();
	//void SetOnkoLiikkunut(bool liikkunut);
};

