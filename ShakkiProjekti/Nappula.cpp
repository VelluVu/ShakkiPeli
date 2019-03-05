#include "Nappula.h"

Nappula::Nappula(std::wstring uni, int col, int code)
{

	_unicode = uni;
	_vari = col;
	_koodi = code;

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

	_unicode = uni;

}

std::wstring Nappula::GetUnicode()
{
	return std::wstring(_unicode);
}

void Nappula::SetVari(int col)
{

	_vari = col;

}

int Nappula::GetVari()
{
	return _vari;
}
