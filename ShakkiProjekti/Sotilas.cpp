#include "Sotilas.h"
#include "Asema.h"


void Sotilas::AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari)
{

	//std::wcout << "<<<<<<SOTILAAN SIIRROT>>>>>> " << std::endl;

	//wchar_t nappi = 'S';
	int x = pos->GetSarake();
	int y = pos->GetRivi();
	Ruutu _pos(x, y);

	int vastustajanVari;

	if (vari == 0)
	{
		//std::wcout << "Valkoisen sotilaan siirrot: " << std::endl;

		//valkoisen sotilaan siirrot

		//VALKOISEN viistosiirrot oikea 1 ; 1 vasen -1 ; 1
		if (x + 1 < 8) { // tarkastetaan että pysytään laudalla
			if (asema->lauta[x + 1][y + 1] != nullptr) {
				// Tarkistetaan että jos lähtöruudussa olevan nappulan väri on sama kuin tarkastelun alaisessa ruudussa, niin silloin on oma nappula
				vastustajanVari = asema->lauta[x + 1][y + 1]->GetVari();
				if (vari == vastustajanVari) {}
				// jos vihollisen nappula niin syyään
				if (vari != vastustajanVari) {
					if (y < 6) {
						lista.push_back(Siirto(*pos, Ruutu(x + 1, y + 1)));
					}
					else {
						LisaaSotilaanKorotukset(&Siirto(*pos, Ruutu(x + 1, y + 1)), lista, asema);
					}
				}
			}
		}
		if (x - 1 >= 0) {
			if (asema->lauta[x - 1][y + 1] != nullptr) {
				vastustajanVari = asema->lauta[x - 1][y + 1]->GetVari();
				if (vastustajanVari == vastustajanVari) {}
				if (vari != vastustajanVari) {
					if (y < 6) {
						lista.push_back(Siirto(*pos, Ruutu(x - 1, y + 1)));
					}
					else {
						LisaaSotilaanKorotukset(&Siirto(*pos, Ruutu(x - 1, y + 1)), lista, asema);
					}
				}
			}
		}

		int _tx[4] = { 0, 0};
		int _ty[4] = { 1, 2};

		for (int i = 0; i < 2; i++)
		{
			int tx = x + _tx[i];
			int ty = y + _ty[i];
			Ruutu _target(tx, ty);

			//jos yli laidan mennään seuraavaan suunta iteraatioon
			if (tx < 0 && tx > 7 && ty < 0 && ty > 7)
			{
				continue;
			}
			//Jos vain liike kyseessä
			if (i < 2 && asema->lauta[tx][ty] == nullptr)
			{
				//mahdollista liikkua 2 kertaa jos ei ole liikkunut EIKÄ PASSAA HYPÄTÄ OMAN YLI!
				if (y == 1 && i == 1 && asema->lauta[tx][ty - 1] == nullptr)
				{
					Siirto liikuKaksi(_pos, _target);
					lista.push_back(liikuKaksi);
					//std::wcout << "Liiku kaks : "; liikuKaksi.TulostaRuudut();
				}
				//jos on indexi 0 niin aseta perussiirto listaan
				else if (i == 0 && ty != 7)
				{
					Siirto liikuYks(_pos, _target);
					lista.push_back(liikuYks);
					//std::wcout << "Liiku yks : "; liikuYks.TulostaRuudut();
				}
				//jos mennään mustan päätyyn lisätään sotilaan korotus listaan.
				else if (y == 6 && ty == 7)
				{
					Siirto korotus(_pos, _target);
					LisaaSotilaanKorotukset(&korotus, lista, asema);
				}
			}
		}
	}

	if (vari == 1)
	{

		//std::wcout << "Mustan sotilaan siirrot: " << std::endl;

		//mustan sotilaan siirrot

		//MUSTAN viistosiirrot oikea 1 ; -1 vasen -1 ; -1
		if (x + 1 < 8) { // tarkastetaan reuna
			if (asema->lauta[x + 1][y - 1] != nullptr) {
				vastustajanVari = asema->lauta[x + 1][y - 1]->GetVari();
				if (vari == vastustajanVari) {
				}
				if (vari != vastustajanVari) {
					if (y > 1)
						lista.push_back(Siirto(*pos, Ruutu(x + 1, y - 1)));
					else
						LisaaSotilaanKorotukset(&Siirto(*pos, Ruutu(x + 1, y - 1)), lista, asema);
				}
			}
		}
		if (x - 1 >= 0) {
			if (asema->lauta[x - 1][y - 1] != nullptr) {
				vastustajanVari = asema->lauta[x - 1][y - 1]->GetVari();
				if (vastustajanVari == vastustajanVari) {
				}
				if (vari != vastustajanVari) {
					if (y > 1)
						lista.push_back(Siirto(*pos, Ruutu(x - 1, y - 1)));
					else
						LisaaSotilaanKorotukset(&Siirto(*pos, Ruutu(x - 1, y - 1)), lista, asema);
				}
			}
		}

		int _tx[4] = { 0, 0};
		int _ty[4] = { -1, -2};

		for (int i = 0; i < 2; i++)
		{
			int tx = x + _tx[i];
			int ty = y + _ty[i];
			Ruutu _target(tx, ty);

			if (tx < 0 && tx > 7 && ty < 0 && ty > 7)
			{
				continue;
			}
			//std::wcout << "Target X:" << tx << " Target Y:" << ty << std::endl;
			//Jos vain liike kyseessä
			if (i < 2 && asema->lauta[tx][ty] == nullptr) {
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
				//Saavutaan valkoisten päätyyn korotus
				else if (y == 1 && ty == 0)
				{
					Siirto korotus(_pos, _target);
					LisaaSotilaanKorotukset(&korotus, lista, asema);
				}
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
				Ruutu _target(asema->kaksoisaskelSarakkeella, 5);
				Siirto ohestaLyonti(_pos, _target, true);
				lista.push_back(ohestaLyonti);
			}
		}
		if (vari == 1 && y == 3)
		{
			if (asema->lauta[asema->kaksoisaskelSarakkeella][3] && 
				asema->lauta[asema->kaksoisaskelSarakkeella][3]->GetKoodi() == VS)
			{
				Ruutu _target(asema->kaksoisaskelSarakkeella, 2);
				Siirto ohestaLyonti(_pos, _target, true);
				lista.push_back(ohestaLyonti);
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
		lista.push_back(daamiksi);

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
		lista.push_back(daamiksi);

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
