#include "Torni.h"
#include "Asema.h"

void Torni::AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari)
{
	wchar_t nappi = 'T';
	Ruutu _pos(pos->GetRivi(), pos->GetSarake());
	Ruutu _target(pos->GetRivi(), pos->GetSarake());
	

	//Tornien liike yl�s 
	for (size_t i = 1; i <= 8; i++)
	{
		//Liiku niin pitk��n suoraan kunnes seuraava ei ole en��n nullptr tai eriv�rinen nappi on edess�
		if (asema->lauta[pos->GetRivi() + i][pos->GetSarake()] == nullptr ||
			asema->lauta[pos->GetRivi() + i][pos->GetSarake()]->GetVari() != vari)
		{
			Ruutu _target(pos->GetRivi() + i, pos->GetSarake());
			//jos t�rm�� viholliseen sy�
			if (asema->lauta[pos->GetRivi() + i][pos->GetSarake()] != nullptr) {
				if (asema->lauta[pos->GetRivi() + i][pos->GetSarake()]->GetVari() != vari)
				{
					Siirto syoYlos(_pos, _target, nappi);
					lista.push_back(syoYlos);
				}
			}
			else 
			{
				Siirto liikuYlos(_pos, _target, nappi);
				lista.push_back(liikuYlos);
			}
		}
	}

	//Tornien liike alas
	for (size_t i = 1; i <= 8; i++)
	{
		if (asema->lauta[pos->GetRivi() - i][pos->GetSarake()] == nullptr ||
			asema->lauta[pos->GetRivi() - i][pos->GetSarake()]->GetVari() != vari)
		{
			Ruutu _target(pos->GetRivi() - i, pos->GetSarake());
			//jos t�rm�� viholliseen sy�
			if (asema->lauta[pos->GetRivi() - i][pos->GetSarake()] != nullptr) {
				if (asema->lauta[pos->GetRivi() - i][pos->GetSarake()]->GetVari() != vari)
				{
					Siirto syoAlas(_pos, _target, nappi);
					lista.push_back(syoAlas);
				}
			}
			else 
			{
				Siirto liikuAlas(_pos, _target, nappi);
				lista.push_back(liikuAlas);
			}
		}
	}
	
	//Tornien liike oikealle
	for (size_t i = 1; i <= 8; i++)
	{
		//Liiku niin pitk��n suoraan kunnes seuraava ei ole en��n nullptr tai eriv�rinen nappi on edess�
		if (asema->lauta[pos->GetRivi()][pos->GetSarake() + i] == nullptr ||
			asema->lauta[pos->GetRivi()][pos->GetSarake() + i]->GetVari() != vari)
		{
			Ruutu _target(pos->GetRivi(), pos->GetSarake() + i);
			//jos t�rm�� viholliseen sy� jos v�ri on eri ku t�m�n napin v�ri
			if (asema->lauta[pos->GetRivi()][pos->GetSarake() + i] != nullptr) {
				if (asema->lauta[pos->GetRivi()][pos->GetSarake() + i]->GetVari() != vari)
				{
					Siirto syoOikealle(_pos, _target, nappi);
					lista.push_back(syoOikealle);
				}
			}
			else
			{
				Siirto liikuOikealle(_pos, _target, nappi);
				lista.push_back(liikuOikealle);
			}
		}
	}

	//Tornien liike vasemmalle
	for (size_t i = 1; i <= 8; i++)
	{

		if (asema->lauta[pos->GetRivi()][pos->GetSarake() - i] == nullptr ||
			asema->lauta[pos->GetRivi()][pos->GetSarake() - i]->GetVari() != vari)
		{
			Ruutu _target(pos->GetRivi(), pos->GetSarake() - i);
			//jos t�rm�� viholliseen sy�
			if (asema->lauta[pos->GetRivi()][pos->GetSarake() - i] != nullptr) {
				if (asema->lauta[pos->GetRivi()][pos->GetSarake() - i]->GetVari() != vari)
				{
					Siirto syoVasemmalle(_pos, _target, nappi);
					lista.push_back(syoVasemmalle);
				}
			}
			else
			{
				Siirto liikuVasemmalle(_pos, _target, nappi);
				lista.push_back(liikuVasemmalle);
			}
		}
	}
}
