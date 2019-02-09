#include "Sotilas.h"
#include "Asema.h"


void Sotilas::AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari)
{

	std::wcout << "<<<<<<SOTILAAN SIIRROT>>>>>> " << std::endl;
	
	wchar_t nappi = 'S';
	int x = pos->GetSarake();
	int y = pos->GetRivi();
	Ruutu _pos(x, y);

	if (vari == 0) 
	{
		std::wcout << "Valkoisen sotilaan siirrot: " << std::endl;
		//valkoisen sotilaan siirrot
		int _tx[4] = { 0, 0, 1, -1 };
		int _ty[4] = { 1, 2, 1, 1 };
		
		for (int i = 0; i < 4; i++)
		{
			int tx = x + _tx[i];
			int ty = y + _ty[i];
			Ruutu _target(tx, ty);
			//Jos vain liike kyseessä
			if (i < 2 && ty >= 0 && ty <= 7 && asema->lauta[tx][ty] == nullptr) {
				//mahdollista liikkua 2 kertaa jos ei ole liikkunut
				if (!onkoLiikkunut && i == 1) 
				{
					Siirto liikuKaksi(_pos, _target, nappi);
					lista.push_back(liikuKaksi);
					std::wcout << "Liiku kaks : "; liikuKaksi.TulostaRuudut();
					//muista asettaa booli trueksi sotilaan liikkumisen jälkeen
				}
				//jos ei ole indexi 2 niin aseta perussiirto listaan
				else 
				{
					Siirto liikuYks(_pos, _target, nappi);
					lista.push_back(liikuYks);
					std::wcout << "Liiku yks : "; liikuYks.TulostaRuudut();
				}
			}
			else if (asema->lauta[tx][ty] == nullptr && i > 1 && tx >= 0 && tx <= 7 && ty >= 0 && ty <= 7) {
				std::wcout << "Ei ole syötävää nappuaa viistossa!" << std::endl;
				continue;
			}
			//jos viistossa on vihollinen on mahdollista syödä se
			else if (asema->lauta[tx][ty] != nullptr && i > 1 && tx >= 0 && tx <= 7 && ty >= 0 && ty <= 7)
			{
				std::wcout << asema->lauta[tx][ty]->GetKoodi() << std::endl;
				if (i > 1 && asema->lauta[tx][ty]->GetVari() != vari && asema->lauta[tx][ty] != nullptr && tx >= 0 && tx <= 7 && ty >= 0 && ty <= 7)
				{
					Siirto syo(_pos, _target, nappi);
					lista.push_back(syo);
					std::wcout << "Syötävä kohde viistossa : "; syo.TulostaRuudut();
				}
			}
			else 
			{
				std::wcout << "este edessä tai ylilaidan" << std::endl;
			}
		}
	}
	else 
	{
		std::wcout << "Mustan sotilaan siirrot: " << std::endl;
		//mustan sotilaan siirrot
		int _tx[4] = { 0, 0, 1, -1 };
		int _ty[4] = { -1, -2, -1, -1 };

		for (int i = 0; i < 4; i++)
		{
			int tx = x + _tx[i];
			int ty = y + _ty[i];
			Ruutu _target(tx, ty);
			std::wcout << "Target X:" << tx << " Target Y:" << ty << std::endl;
			//Jos vain liike kyseessä
			if (i < 2 && ty >= 0 && ty <= 7 && asema->lauta[tx][ty] == nullptr) {
				//mahdollista liikkua 2 kertaa jos ei ole liikkunut
				if (!onkoLiikkunut && i == 1)
				{
					Siirto liikuKaksi(_pos, _target, nappi);
					lista.push_back(liikuKaksi);
					std::wcout << "Liiku kaks : "; liikuKaksi.TulostaRuudut();
					//muista asettaa booli trueksi sotilaan liikkumisen jälkeen
				}
				//jos indexi ei ole 1 mutta kuitenkin alle 2 niin lisää mahdollinen perus siirto listaan
				else 
				{
					Siirto liikuYks(_pos, _target, nappi);
					lista.push_back(liikuYks);
					std::wcout << "Liiku yks : "; liikuYks.TulostaRuudut();
				}	
			}
			else if (asema->lauta[tx][ty] == nullptr && i > 1 && tx >= 0 && tx <= 7 && ty >= 0 && ty <= 7) {
				std::wcout << "Ei ole syötävää nappuaa viistossa!" << std::endl;
				continue;
			}
			//jos viistossa on vihollinen on mahdollista syödä se
			else if (asema->lauta[tx][ty] != nullptr && i > 1 && tx >= 0 && tx <= 7 && ty >= 0 && ty <= 7)
			{
				std::wcout << asema->lauta[tx][ty]->GetKoodi() << std::endl;
				if (i > 1 && asema->lauta[tx][ty] != nullptr && asema->lauta[tx][ty]->GetVari() != vari && tx >= 0 && tx <= 7 && ty >= 0 && ty <= 7)
				{
					Siirto syo(_pos, _target, nappi);
					lista.push_back(syo);
					std::wcout << "Syötävä kohde viistossa : "; syo.TulostaRuudut();
				}
			}
			else
			{
				std::wcout << "Este edessä tai ylilaidan " << std::endl;
			}
		}
	}
	std::wcout << "<<<<<<SOTILAAN SIIRROT LOPPUU>>>>>> " << std::endl << std::endl;
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
