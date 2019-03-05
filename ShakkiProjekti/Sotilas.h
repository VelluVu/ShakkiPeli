#pragma once
#include "Nappula.h"

class Sotilas :
	public Nappula
{

private: 
	bool onkoLiikkunut;

public:
	void AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari);
	Sotilas(std::wstring uni, int col, int code) : Nappula(uni, col, code) {
	onkoLiikkunut = false;
	};
	//bool GetOnkoLiikkunut();
	//void SetOnkoLiikkunut(bool liikkunut);
	void LisaaSotilaanKorotukset(Siirto* siirto, std::list<Siirto>& lista, Asema* asema);
};
