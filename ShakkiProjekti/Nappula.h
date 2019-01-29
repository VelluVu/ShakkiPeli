#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Siirto.h"
#include "Ruutu.h"

// Vakioarvot nappulatyypeille.
enum
{
	VT, VR, VL, VD, VK, VS,
	MT, MR, ML, MD, MK, MS
};

class Asema;

class Nappula {

private:
	std::wstring unicode;
	int vari; // valkea = 0, musta = 1
	int _koodi; // VT, VR, MT tms.
public:
	Nappula(std::wstring uni, int col, int code);
	Nappula();
	~Nappula();
	void SetKoodi(int code);
	int GetKoodi();
	void SetUnicode(std::wstring uni);
	std::wstring GetUnicode();
	void SetVari(int col);
	int GetVari();
	virtual void AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari) = 0;
};


