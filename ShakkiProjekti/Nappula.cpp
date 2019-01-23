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

void Nappula::SetKoodi(int code)
{

	_koodi = code;

}

int Nappula::GetKoodi()
{
	return _koodi;
}

void Nappula::SetUnicode(std::wstring uni)
{

	unicode = uni;

}

std::wstring Nappula::GetUnicode()
{
	return std::wstring(unicode);
}

void Nappula::SetVari(int col)
{

	vari = col;

}

int Nappula::GetVari()
{
	return vari;
}


Nappula::~Nappula()
{
}
