#pragma once
#include "Nappula.h"
#include "Lahetti.h"
#include "Torni.h"

class Kuningatar : 
	 public Torni, public Lahetti, public Nappula
{
public:

	void AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari);
	Kuningatar(std::wstring uni, int col, int code) : Torni(uni, col, code),Lahetti(uni, col, code), Nappula(uni, col, code) {};

};

