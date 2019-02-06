#include "Lahetti.h"
#include "Asema.h"

void Lahetti::AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari)
{
	wchar_t nappi = 'L';
	Ruutu _pos(pos->GetRivi(), pos->GetSarake());
	Ruutu _target(pos->GetRivi(), pos->GetSarake());

	//L�hetin liike oikealle yl�s viistoon
	for (int i = 1; i <= 8; i++)
	{
		if (asema->lauta[pos->GetRivi() + i][pos->GetSarake() + i] == nullptr ||
			asema->lauta[pos->GetRivi() + i][pos->GetSarake() + i]->GetVari() != vari)
		{
			Ruutu _target(pos->GetRivi() + i, pos->GetSarake() + i);
			if (asema->lauta[pos->GetRivi() + i][pos->GetSarake() + i] != nullptr) {
				if (asema->lauta[pos->GetRivi() + i][pos->GetSarake() + i]->GetVari() != vari)
				{
					Siirto syoYlosOikea(_pos, _target, nappi);
					lista.push_front(syoYlosOikea);
				}
			}
			else
			{
				Siirto ylosOikea(_pos, _target, nappi);
				lista.push_front(ylosOikea);
			}
		}
	}

	//L�hetin liike vasemmalle yl�s viistoon

	for (int i = 1; i <= 8; i++)
	{
		if (asema->lauta[pos->GetRivi() + i][pos->GetSarake() - i] == nullptr ||
			asema->lauta[pos->GetRivi() + i][pos->GetSarake() + i]->GetVari() != vari)
		{
			Ruutu _target(pos->GetRivi() + i, pos->GetSarake() - i);

			if (asema->lauta[pos->GetRivi() + i][pos->GetSarake() - i] != nullptr) {
				if (asema->lauta[pos->GetRivi() + i][pos->GetSarake() - i]->GetVari() != vari)
				{
					Siirto syoYlosVasen(_pos, _target, nappi);
					lista.push_front(syoYlosVasen);
				}
			}
			else
			{
				Siirto ylosVasen(_pos, _target, nappi);
				lista.push_front(ylosVasen);
			}
		}
	}

	//L�hetin liike vasemmalle alas viistoon

	for (int i = 1; i <= 8; i++)
	{
		if (asema->lauta[pos->GetRivi() - i][pos->GetSarake() - i] == nullptr ||
			asema->lauta[pos->GetRivi() + i][pos->GetSarake() + i]->GetVari() != vari)
		{
			Ruutu _target(pos->GetRivi() - i, pos->GetSarake() - i);

			if (asema->lauta[pos->GetRivi() - i][pos->GetSarake() - i] != nullptr) {
				if (asema->lauta[pos->GetRivi() - i][pos->GetSarake() - i]->GetVari() != vari)
				{
					Siirto syoAlasVasen(_pos, _target, nappi);
					lista.push_front(syoAlasVasen);
				}
			}
			else
			{
				Siirto alasVasen(_pos, _target, nappi);
				lista.push_front(alasVasen);
			}
		}
	}

	//L�hetin liike oikealle alas viistoon
	/*
	 -  -  -  -  -  -  -  -
	 -  -  -  -  -  -  -  -
	 -  L -  -  -  -  -  -
	 -  -  *  -  -  -  -  -
	 -  -  -  *  -  -  -  -
	 -  -  -  -  *  -  -  -
	 -  -  -  -  -  *  -  -
						 ?
	 */

	for (int i = 1; i <= 8; i++)
	{
		if (asema->lauta[pos->GetRivi() - i][pos->GetSarake() + i] == nullptr ||
			asema->lauta[pos->GetRivi() + i][pos->GetSarake() + i]->GetVari() != vari)
		{
			Ruutu _target(pos->GetRivi() - i, pos->GetSarake() + i);

			if (asema->lauta[pos->GetRivi() - i][pos->GetSarake() + i] != nullptr)
			{
				if (asema->lauta[pos->GetRivi() - i][pos->GetSarake() + i]->GetVari() != vari)
				{
					Siirto syoAlasOikea(_pos, _target, nappi);
					lista.push_front(syoAlasOikea);
				}
			}
			else
			{
				Siirto alasOikea(_pos, _target, nappi);
				lista.push_front(alasOikea);
			}
		}
	}
}