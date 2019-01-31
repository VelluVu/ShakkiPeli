#include "Kuningas.h"
#include "Asema.h"

void Kuningas::AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari)
{
	wchar_t nappi = 'K';
	Ruutu _pos(pos->GetRivi(), pos->GetSarake());
	Ruutu _target(pos->GetRivi(), pos->GetSarake());

	//Kuninkaan siirrot yläpuolelta
	for (int i = -1; i < 2; i++)
	{
		if (asema->lauta[pos->GetRivi() + 1][pos->GetSarake() + i] == nullptr ||
			asema->lauta[pos->GetRivi() + 1][pos->GetSarake() + i]->GetVari() != vari) 
		{
			Ruutu _target(pos->GetRivi() + 1, pos->GetSarake() + i);

			if (asema->lauta[pos->GetRivi() + 1][pos->GetSarake() + i]->GetVari() != vari) {
				Siirto syoYlos(_pos, _target, nappi);
				lista.push_front(syoYlos);
			}
			else 
			{
				Siirto ylos(_pos, _target, nappi);
				lista.push_front(ylos);
			}
		}
	}
	//Kuninkaan siirrot Alapuolelta
	for (int i = -1; i < 2; i++)
	{
		if (asema->lauta[pos->GetRivi() - 1][pos->GetSarake() + i] == nullptr ||
			asema->lauta[pos->GetRivi() - 1][pos->GetSarake() + i]->GetVari() != vari)
		{
			Ruutu _target(pos->GetRivi() - 1, pos->GetSarake() + i);

			if (asema->lauta[pos->GetRivi() - 1][pos->GetSarake() + i]->GetVari() != vari) {
				Siirto syoAlas(_pos, _target, nappi);
				lista.push_front(syoAlas);
			}
			else
			{
				Siirto alas(_pos, _target, nappi);
				lista.push_front(alas);
			}
		}
	}

	//Kuninkaan oikea
	if (asema->lauta[pos->GetRivi()][pos->GetSarake() + 1] == nullptr ||
		asema->lauta[pos->GetRivi()][pos->GetSarake() + 1]->GetVari() != vari) 
	{
		Ruutu _target(pos->GetRivi() , pos->GetSarake() + 1);

		if (asema->lauta[pos->GetRivi()][pos->GetSarake() + 1]->GetVari() != vari) {
			Siirto syoOikea(_pos, _target, nappi);
			lista.push_front(syoOikea);
		}
		else
		{
			Siirto oikea(_pos, _target, nappi);
			lista.push_front(oikea);
		}
	}

	//Kuninkaan vasen
	if (asema->lauta[pos->GetRivi()][pos->GetSarake() - 1] == nullptr ||
		asema->lauta[pos->GetRivi()][pos->GetSarake() - 1]->GetVari() != vari)
	{
		Ruutu _target(pos->GetRivi(), pos->GetSarake() - 1);

		if (asema->lauta[pos->GetRivi()][pos->GetSarake() - 1]->GetVari() != vari) {
			Siirto syoVasen(_pos, _target, nappi);
			lista.push_front(syoVasen);
		}
		else
		{
			Siirto vasen(_pos, _target, nappi);
			lista.push_front(vasen);
		}
	}
}
