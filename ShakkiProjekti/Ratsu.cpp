#include "Ratsu.h"
#include "Asema.h"

void Ratsu::AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari)
{
	//std::wcout << "<<<<<<RATSUN SIIRROT>>>>>> " << std::endl;

	wchar_t nappi = 'R';
	int x = pos->GetSarake();
	int y = pos->GetRivi();
	Ruutu _pos(x, y);
	//std::wcout << "<AnnaSiirrot>AlkuPositio x : " << x << " <AnnaSiirrot>AlkuPositio y : " << y << std::endl;

	int _tx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int _ty[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	for (int i = 0; i < 8; i++)
	{
		//Asetetaan kohde koordinaatit
		int tx = x + _tx[i];
		int ty = y + _ty[i];
		Ruutu _target(tx,ty);
		
		//Jos liike pysyy rajojen sisällä ja kohteessa ei ole tyhjäpaikka syö
		if (tx <= 7 && ty <= 7 && tx >= 0 && ty >= 0 && asema->lauta[tx][ty] != nullptr && asema->lauta[tx][ty]->GetVari() != vari) 
		{
			Siirto syo(_pos, _target, nappi);
			lista.push_back(syo);
			//std::wcout << "Syötävä kohde : "; syo.TulostaRuudut();
		}
		//Jos liike pysyy rajojen sisällä ja kohteessa on tyhjäpaikka liiku paikkaan ja aseta siirto 
		else if (tx <= 7 && ty <= 7 && tx >= 0 && ty >= 0 && asema->lauta[tx][ty] == nullptr) 
		{
			Siirto liiku(_pos, _target, nappi);
			lista.push_back(liiku);
			//std::wcout << "Mahdollinen liike : "; liiku.TulostaRuudut();

		}
		else if (tx <= 7 && ty <= 7 && tx >= 0 && ty >= 0 && asema->lauta[tx][ty] != nullptr && asema->lauta[tx][ty]->GetVari() == vari)
		{
			//std::wcout << "Kohteessa on omaUkkeli kohde x : " << tx << " kohde y : " << ty << std::endl;
		}
		else 
		{
			//std::wcout << "Meni ylilaidan kohde x : " << tx << " kohde y : " << ty  << std::endl;
		}
	}

	//std::wcout << "<<<<<<RATSUN SIIRROT LOPPUU>>>>>> " << std::endl << std::endl;

}

//bool Ratsu::GetOnkoLiikkunut()
//{
//	return false;
//}
//
//void Ratsu::SetOnkoLiikkunut(bool liikkunut)
//{
//}
