#include "Kuningas.h"
#include "Asema.h"

void Kuningas::AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari)
{

	//std::wcout << "<<<<<<KUNINKAAN SIIRROT>>>>>> " << std::endl;

	/*wchar_t nappi = 'K';*/
	int x = pos->GetSarake();
	int y = pos->GetRivi();
	Ruutu _pos(x, y);

	int _tx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
	int _ty[8] = {1, 1, 0, -1, -1, -1, 0, 1};

	for (int i = 0; i < 8; i++)
	{
		int tx = x + _tx[i];
		int ty = y + _ty[i];
		Ruutu _target(tx, ty);

		if (tx < 0 || ty < 0 || tx > 7 || ty > 7) 
		{
			//hyppää seuraavaan iteraatioon, koska ei voida mennä ylilaidan
			continue;
		}

		//Liikkuminen
		if (asema->lauta[tx][ty] != nullptr && asema->lauta[tx][ty]->GetVari() == vari)
		{
			//oma nappi edessä ei voi liikkua, siirry seuraavaan liikkeeseen
			continue;
		}
		//Syönti
		else if (asema->lauta[tx][ty] != nullptr && asema->lauta[tx][ty]->GetVari() != vari) 
		{
			Siirto kuningasSyo(_pos, _target);
			lista.push_back(kuningasSyo);
			//std::wcout << "Kuningas syö  : "; kuningasSyo.TulostaRuudut();
		}
		else 
		{
			Siirto kuningasLiiku(_pos, _target);
			lista.push_back(kuningasLiiku);
			//std::wcout << "Kuningas liike  : "; kuningasLiiku.TulostaRuudut();
		}

	}
	
	//std::wcout << "<<<<<<KUNINKAAN SIIRROT LOPPUU>>>>>> " << std::endl << std::endl;
}

//bool Kuningas::GetOnkoLiikkunut()
//{
//	return false;
//}
//
//void Kuningas::SetOnkoLiikkunut(bool liikkunut)
//{
//}
