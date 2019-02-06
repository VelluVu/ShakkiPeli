#include "Sotilas.h"
#include "Asema.h"


void Sotilas::AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari)
{
	//nappi on ite lis�tty voi olla k�ytt�� en tii�...
	wchar_t nappi = 'S';
	Ruutu _pos(pos->GetRivi(), pos->GetSarake());
	Ruutu _target(pos->GetRivi(), pos->GetSarake());

	//testataan onko perusliikkeell� estett�, jos ei niin laitetaan mahdollinen siirto listaan.
	if (vari == 0 && asema->lauta[pos->GetRivi() + 1][pos->GetSarake()] == nullptr)
	{
		Ruutu _target(pos->GetRivi() + 1, pos->GetSarake());
		Siirto perusSiirto(_pos, _target, nappi);
		lista.push_back(perusSiirto);
	}
	else if (vari == 1 && asema->lauta[pos->GetRivi() - 1][pos->GetSarake()] == nullptr)
	{
		Ruutu _target(pos->GetRivi() - 1, pos->GetSarake());
		Siirto perusSiirto(_pos, _target, nappi);
		lista.push_back(perusSiirto);
	}



	//Tuplasiirto mahdollinen jos ei ole jo liikkunut kertaalleen
	if (onkoLiikkunut == false && vari == 0 && asema->lauta[pos->GetRivi() + 1][pos->GetSarake()] == nullptr &&
		asema->lauta[pos->GetRivi() + 2][pos->GetSarake()] == nullptr)
	{
		Ruutu _target(pos->GetRivi() + 2, pos->GetSarake());
		Siirto tuplaSiirto(_pos, _target, nappi);
		lista.push_back(tuplaSiirto);
	}
	else if (vari == 1 && onkoLiikkunut == false && asema->lauta[pos->GetRivi() - 1][pos->GetSarake()] == nullptr &&
		asema->lauta[pos->GetRivi() - 2][pos->GetSarake()] == nullptr)
	{
		Ruutu _target(pos->GetRivi() - 2, pos->GetSarake());
		Siirto tuplaSiirto(_pos, _target, nappi);
		lista.push_back(tuplaSiirto);
	}

	//Sy� vihollinen viistoon vasemmalle
	if (vari == 0 && asema->lauta[pos->GetRivi() + 1][pos->GetSarake() - 1] != nullptr) 
	{
		if (vari == 0 && asema->lauta[pos->GetRivi() + 1][pos->GetSarake() - 1]->GetVari() == 1) {
			Ruutu _target(pos->GetRivi() + 1, pos->GetSarake() - 1);
			Siirto syoVas(_pos, _target, nappi);
			lista.push_back(syoVas);
		}
	}
	else if (vari == 1 && asema->lauta[pos->GetRivi() - 1][pos->GetSarake() - 1] != nullptr)
	{
		if (vari == 1 && asema->lauta[pos->GetRivi() - 1][pos->GetSarake() - 1]->GetVari() == 0)
		{
			Ruutu _target(pos->GetRivi() - 1, pos->GetSarake() - 1);
			Siirto syoVas(_pos, _target, nappi);
			lista.push_back(syoVas);
		}
	}


	//Sy� vihollinen viistoon oikealle
	if (vari == 0 && asema->lauta[pos->GetRivi() + 1][pos->GetSarake() + 1] != nullptr) 
	{
		if (vari == 0 && asema->lauta[pos->GetRivi() + 1][pos->GetSarake() + 1]->GetVari() == 1) {
			Ruutu _target(pos->GetRivi() + 1, pos->GetSarake() + 1);
			Siirto syoOik(_pos, _target, nappi);
			lista.push_back(syoOik);
		}
	}
	else if (vari == 1 && asema->lauta[pos->GetRivi() - 1][pos->GetSarake() + 1] != nullptr) 
	{
		if (vari == 1 && asema->lauta[pos->GetRivi() - 1][pos->GetSarake() + 1]->GetVari() == 0)
		{
			Ruutu _target(pos->GetRivi() - 1, pos->GetSarake() + 1);
			Siirto syoOik(_pos, _target, nappi);
			lista.push_back(syoOik);

		}
	}
}

bool Sotilas::OnkoSotilasLiikkunut()
{
	if (onkoLiikkunut == true) {
		return true;
	}
	else if (onkoLiikkunut == false) {
		return false;
	}
}
