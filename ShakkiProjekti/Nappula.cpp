#include "Nappula.h"



Nappula::Nappula(std::wstring uni, int col, int code)
{

	unicode = uni;
	vari = col;
	_koodi = code;

}

Nappula::Nappula()
{
}

void Nappula::setKoodi(int code)
{

	_koodi = code;

}

int Nappula::getKoodi()
{
	return _koodi;
}

void Nappula::setUnicode(std::wstring uni)
{

	unicode = uni;

}

std::wstring Nappula::getUnicode()
{
	return std::wstring(unicode);
}

void Nappula::setVari(int col)
{

	vari = col;

}

int Nappula::getVari()
{
	return vari;
}


Nappula::~Nappula()
{
}
