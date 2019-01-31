#include "Lahetti.h"
#include "Asema.h"

void Lahetti::AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari)
{
	wchar_t nappi = 'L';
	Ruutu _pos(pos->GetRivi(), pos->GetSarake());
	Ruutu _target(pos->GetRivi(), pos->GetSarake());

	//Lähetin liike oikealle ylös viistoon
	for (int i = 1; i <= 8 ; i++)
	{
		if (asema->lauta[pos->GetRivi() + i][pos->GetSarake() + i] == nullptr ||
			asema->lauta[pos->GetRivi() + i][pos->GetSarake() + i]->GetVari() != vari)
		{
			Ruutu _target(pos->GetRivi() + i, pos->GetSarake() + i);

			if (asema->lauta[pos->GetRivi() + i][pos->GetSarake() + i]->GetVari() != vari)
			{
				Siirto syoYlosOikea(_pos, _target, nappi);
				lista.push_front(syoYlosOikea);
			}
			else
			{
				Siirto ylosOikea(_pos, _target, nappi);
				lista.push_front(ylosOikea);
			}
		}
	}

	//Lähetin liike vasemmalle ylös viistoon

	for (int i = 1; i <= 8; i++)
	{
		if (asema->lauta[pos->GetRivi() + i][pos->GetSarake() - i] == nullptr ||
			asema->lauta[pos->GetRivi() + i][pos->GetSarake() + i]->GetVari() != vari)
		{
			Ruutu _target(pos->GetRivi() + i, pos->GetSarake() - i);

			if (asema->lauta[pos->GetRivi() + i][pos->GetSarake() - i]->GetVari() != vari)
			{
				Siirto syoYlosVasen(_pos, _target, nappi);
				lista.push_front(syoYlosVasen);
			}
			else
			{
				Siirto ylosVasen(_pos, _target, nappi);
				lista.push_front(ylosVasen);
			}
		}
	}

	//Lähetin liike vasemmalle alas viistoon

	for (int i = 1; i <= 8; i++)
	{
		if (asema->lauta[pos->GetRivi() - i][pos->GetSarake() - i] == nullptr ||
			asema->lauta[pos->GetRivi() + i][pos->GetSarake() + i]->GetVari() != vari)
		{
			Ruutu _target(pos->GetRivi() - i, pos->GetSarake() - i);

			if (asema->lauta[pos->GetRivi() - i][pos->GetSarake() - i]->GetVari() != vari)
			{
				Siirto syoAlasVasen(_pos, _target, nappi);
				lista.push_front(syoAlasVasen);
			}
			else
			{
				Siirto alasVasen(_pos, _target, nappi);
				lista.push_front(alasVasen);
			}
		}
	}

	//Lähetin liike oikealle alas viistoon
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

			if (asema->lauta[pos->GetRivi() - i][pos->GetSarake() + i]->GetVari() != vari)
			{
				Siirto syoAlasOikea(_pos, _target, nappi);
				lista.push_front(syoAlasOikea);
			}
			else
			{
				Siirto alasOikea(_pos, _target, nappi);
				lista.push_front(alasOikea);
			}
		}
	}
	

	
}
