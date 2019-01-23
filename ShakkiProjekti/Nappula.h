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
	void SetKoodi(int code);
	int GetKoodi();
	void SetUnicode(std::wstring uni);
	std::wstring GetUnicode();
	void SetVari(int col);
	int GetVari();
};


