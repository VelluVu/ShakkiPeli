#pragma once
#include <iostream>
#include <string>
// Vakioarvot nappulatyypeille.
enum
{
	VT, VR, VL, VD, VK, VS,
	MT, MR, ML, MD, MK, MS
};

class Nappula {

private:
	std::wstring unicode;
	int vari; // valkea = 0, musta = 1
	int _koodi; // VT, VR, MT tms.
public:
	Nappula(std::wstring uni, int col, int code);
	Nappula();
	~Nappula();
	void setKoodi(int code);
	int getKoodi();
	void setUnicode(std::wstring uni);
	std::wstring getUnicode();
	void setVari(int col);
	int getVari();
};


