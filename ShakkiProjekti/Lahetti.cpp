#include "Lahetti.h"
#include "Asema.h"

void Lahetti::AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari)
{

	//std::wcout << "<<<<<<LÄHETIN SIIRROT>>>>>> " << std::endl;

	int _tx[] = {-1, 1, 1, -1};
	int _ty[] = {1, 1, -1, -1};
	int x = pos->GetSarake();
	int y = pos->GetRivi();
	Ruutu _pos(x, y);
	wchar_t nappi;
	
	//std::wcout << "Lähetin alkuPositio: (" << x << ";" << y << ")" << std::endl;

	if (asema->lauta[x][y]->GetKoodi() == VD || asema->lauta[x][y]->GetKoodi() == MD) 
	{
		nappi = 'D';
	}
	else
	{
		nappi = 'L';
	}

	for (int i = 0; i < 4; i++)
	{
		int tx = x + _tx[i];
		int ty = y + _ty[i];		
		
		//Mennään eteenpäin kunnes maksimi siirtymä on tehty tai if tsekkaukset hoksaa probleeman
		for (int j = 0 ; j < 8 ; j++)
		{
			int tx = x + _tx[i];
			int ty = y + _ty[i];
			
			//tarkastetaan suunta
			if (i == 0) 
			{
				//jos suunta on tx -1 ty +1 , vasenylös 
				tx -=  j;
				ty += j;
			}
			else if (i == 1) 
			{
				//jos ylösoikealle tx +1 ty +1
				tx += j;
				ty += j;
			}
			else	if (i == 2)
			{
				//jos alasoikealle tx + 1 ty - 1
				tx += j;
				ty -= j;
			}
			else if (i == 3)
			{
				//jos alasvasemmalle tx - 1 ty - 1
				tx -= j;
				ty -= j;
			}
			//std::wcout << "Lähetin kohde : (" << tx << ";" << ty << ")" << std::endl;
			Ruutu _target(tx, ty);
			//Katsotaan onko menny yli minkään laidan
			if (tx > 7 || tx < 0 || ty > 7 || ty < 0)
			{
				//reunan yli kohteessa, tämän suunnan tarkistus loppuu			
				break;
			}
			else if (asema->lauta[tx][ty] != nullptr && asema->lauta[tx][ty]->GetVari() == vari)
			{
				//oma nappi kohteessa, ei voida jatkaa tähän suuntaan
				break;
			}
			else if (asema->lauta[tx][ty] != nullptr && asema->lauta[tx][ty]->GetVari() != vari)
			{
				//vihollisen nappi kohteessa, tehdään syönti siirto ja lopetetaan suunnan tarkistus
				Siirto syo(_pos, _target, nappi);
				lista.push_back(syo);
				break;
			}
			else if(asema->lauta[tx][ty] == nullptr)
			{
				//Muuten siirrytään seuraavaan ruutuun kyseisessä suunnassa ja lisätään mahdollinen siirto listaan
				Siirto liiku(_pos, _target, nappi);
				lista.push_back(liiku);		
			}
		}
	}
	//std::wcout << "<<<<<<LÄHETIN SIIRROT LOPPUU>>>>>> " << std::endl;
}

bool Lahetti::GetOnkoLiikkunut()
{
	return false;
}

void Lahetti::SetOnkoLiikkunut(bool liikkunut)
{
}
