#include "Sotilas.h"
#include "Asema.h"


void Sotilas::AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari)
{

	//std::wcout << "<<<<<<SOTILAAN SIIRROT>>>>>> " << std::endl;

	//wchar_t nappi = 'S';
	int x = pos->GetSarake();
	int y = pos->GetRivi();
	Ruutu _pos(x, y);

	if (vari == 0)
	{
		//std::wcout << "Valkoisen sotilaan siirrot: " << std::endl;
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
				//mahdollista liikkua 2 kertaa jos ei ole liikkunut EIKÄ PASSAA HYPÄTÄ OMAN YLI!
				if (y == 1 && i == 1 && asema->lauta[tx][ty - 1] == nullptr)
				{
					Siirto liikuKaksi(_pos, _target);
					lista.push_back(liikuKaksi);
					//std::wcout << "Liiku kaks : "; liikuKaksi.TulostaRuudut();
					//muista asettaa booli trueksi sotilaan liikkumisen jälkeen päivitäasemassa
				}
				//jos ei ole indexi 2 niin aseta perussiirto listaan
				else if (i == 0 && ty != 7)
				{
					Siirto liikuYks(_pos, _target);
					lista.push_back(liikuYks);
					//std::wcout << "Liiku yks : "; liikuYks.TulostaRuudut();
				}
				else if (y == 6 && ty == 7)
				{
					Siirto korotus(_pos, _target);
					LisaaSotilaanKorotukset(&korotus, lista, asema);
				}
			}
			else if (asema->lauta[tx][ty] == nullptr && i > 1 && tx >= 0 && tx <= 7 && ty >= 0 && ty <= 7) {
				//std::wcout << "Ei ole syötävää nappuaa viistossa!" << std::endl;
				continue;
			}
			//jos viistossa on vihollinen on mahdollista syödä se
			else if (asema->lauta[tx][ty] != nullptr && i > 1 && tx >= 0 && tx <= 7 && ty >= 0 && ty <= 7)
			{
				//std::wcout << asema->lauta[tx][ty]->GetKoodi() << std::endl;
				if (i > 1 && asema->lauta[tx][ty]->GetVari() != vari &&
					asema->lauta[tx][ty] != nullptr &&
					tx >= 0 && tx <= 7 && ty >= 0 && ty <= 7 && ty != 7)
				{
					Siirto syo(_pos, _target);
					lista.push_front(syo);
					//std::wcout << "Syötävä kohde viistossa : "; syo.TulostaRuudut();
				}
				else if (i > 1 && asema->lauta[tx][ty] != nullptr &&
					asema->lauta[tx][ty]->GetVari() != vari &&
					tx >= 0 && tx <= 7 && ty >= 0 && ty <= 7 && ty == 7)
				{
					Siirto korotus(_pos, _target);
					LisaaSotilaanKorotukset(&korotus, lista, asema);
				}
			}
			else
			{
				//std::wcout << "este edessä tai ylilaidan" << std::endl;
			}
		}
	}
	else
	{
		//std::wcout << "Mustan sotilaan siirrot: " << std::endl;
		//mustan sotilaan siirrot
		int _tx[4] = { 0, 0, 1, -1 };
		int _ty[4] = { -1, -2, -1, -1 };

		for (int i = 0; i < 4; i++)
		{
			int tx = x + _tx[i];
			int ty = y + _ty[i];
			Ruutu _target(tx, ty);
			//std::wcout << "Target X:" << tx << " Target Y:" << ty << std::endl;
			//Jos vain liike kyseessä
			if (i < 2 && ty >= 0 && ty <= 7 && asema->lauta[tx][ty] == nullptr) {
				//mahdollista liikkua 2 kertaa jos ei ole liikkunut EIKÄ PASSAA HYPÄTÄ OMAN YLI!
				if (i == 1 && y == 6 && asema->lauta[tx][ty + 1] == nullptr)
				{
					Siirto liikuKaksi(_pos, _target);
					lista.push_back(liikuKaksi);
					//std::wcout << "Liiku kaks : "; liikuKaksi.TulostaRuudut();
					//muista asettaa booli trueksi sotilaan liikkumisen jälkeen
				}
				//jos indexi ei ole 1 mutta kuitenkin alle 2 niin lisää mahdollinen perus siirto listaan
				else if (i == 0 && ty != 0)
				{
					Siirto liikuYks(_pos, _target);
					lista.push_back(liikuYks);
					//std::wcout << "Liiku yks : "; liikuYks.TulostaRuudut();
				}
				else if (y == 1 && ty == 0)
				{
					Siirto korotus(_pos, _target);
					LisaaSotilaanKorotukset(&korotus, lista, asema);
				}
			}
			else if (asema->lauta[tx][ty] == nullptr && i > 1 && tx >= 0 && tx <= 7 && ty >= 0 && ty <= 7) {
				//std::wcout << "Ei ole syötävää nappuaa viistossa!" << std::endl;
				continue;
			}
			//jos viistossa on vihollinen on mahdollista syödä se
			else if (asema->lauta[tx][ty] != nullptr && i > 1 && tx >= 0 && tx <= 7 && ty >= 0 && ty <= 7)
			{
				//std::wcout << asema->lauta[tx][ty]->GetKoodi() << std::endl;
				if (i > 1 && asema->lauta[tx][ty] != nullptr &&
					asema->lauta[tx][ty]->GetVari() != vari &&
					tx >= 0 && tx <= 7 && ty >= 0 && ty <= 7 && ty != 0)
				{
					Siirto syo(_pos, _target);
					lista.push_front(syo);
					//std::wcout << "Syötävä kohde viistossa : "; syo.TulostaRuudut();
				}
				else if (i > 1 && asema->lauta[tx][ty] != nullptr &&
					asema->lauta[tx][ty]->GetVari() != vari &&
					tx >= 0 && tx <= 7 && ty >= 0 && ty <= 7 && ty == 0)
				{
					Siirto korotus(_pos, _target);
					LisaaSotilaanKorotukset(&korotus, lista, asema);
				}

			}
			else
			{
				//std::wcout << "Este edessä tai ylilaidan " << std::endl;
			}
		}
	}
	
	// Ohestalyönti
	if (asema->kaksoisaskelSarakkeella != -1)
	{
		if (vari == 0 && y == 4)
		{
			if (asema->lauta[asema->kaksoisaskelSarakkeella][4] && 
				asema->lauta[asema->kaksoisaskelSarakkeella][4]->GetKoodi() == MS) 
			{
				if (asema->kaksoisaskelSarakkeella > x) {
					Ruutu _target(x + 1, 5);
					Siirto ohestaLyonti(_pos, _target, true);
					lista.push_front(ohestaLyonti);
				}
				else {
					Ruutu _target(x - 1, 5);
					Siirto ohestaLyonti(_pos, _target, true);
					lista.push_front(ohestaLyonti);
				}
				
			}
		}
		if (vari == 1 && y == 3)
		{
			if (asema->lauta[asema->kaksoisaskelSarakkeella][3] && 
				asema->lauta[asema->kaksoisaskelSarakkeella][3]->GetKoodi() == VS)
			{
				
				if (asema->kaksoisaskelSarakkeella > x) {
					Ruutu _target(x + 1, 2);
					Siirto ohestaLyonti(_pos, _target, true);
					lista.push_front(ohestaLyonti);
				}
				else {
					Ruutu _target(x - 1, 2);
					Siirto ohestaLyonti(_pos, _target, true);
					lista.push_front(ohestaLyonti);
				}
			}
		}
	}

	//std::wcout << "<<<<<<SOTILAAN SIIRROT LOPPUU>>>>>> " << std::endl << std::endl;
}

void Sotilas::LisaaSotilaanKorotukset(Siirto* siirto, std::list<Siirto>& lista, Asema* asema) {
	if (siirto->GetLoppuRuutu().GetRivi() == 7 && asema->lauta[siirto->GetAlkuRuutu().GetSarake()][siirto->GetAlkuRuutu().GetRivi()]->GetKoodi() == VS) {
		// valkea korottaa
		Siirto daamiksi = *siirto;
		daamiksi.miksiKorotetaan = asema->vd;
		lista.push_front(daamiksi);

		Siirto torniksi = *siirto;
		torniksi.miksiKorotetaan = asema->vt;
		lista.push_back(torniksi);

		Siirto lahetiksi = *siirto;
		lahetiksi.miksiKorotetaan = asema->vl;
		lista.push_back(lahetiksi);

		Siirto ratsuksi = *siirto;
		ratsuksi.miksiKorotetaan = asema->vr;
		lista.push_back(ratsuksi);
	}
	else if (siirto->GetLoppuRuutu().GetRivi() == 0 && asema->lauta[siirto->GetAlkuRuutu().GetSarake()][siirto->GetAlkuRuutu().GetRivi()]->GetKoodi() == MS) {
		// musta korottaa
		Siirto daamiksi = *siirto;
		daamiksi.miksiKorotetaan = asema->md;
		lista.push_front(daamiksi);

		Siirto torniksi = *siirto;
		torniksi.miksiKorotetaan = asema->mt;
		lista.push_back(torniksi);

		Siirto lahetiksi = *siirto;
		lahetiksi.miksiKorotetaan = asema->ml;
		lista.push_back(lahetiksi);

		Siirto ratsuksi = *siirto;
		ratsuksi.miksiKorotetaan = asema->mr;
		lista.push_back(ratsuksi);
	}
}
