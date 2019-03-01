#include "Asema.h"

Asema::Asema()
{
	//nollaa ylimääräinen 'tauhka'
	for (size_t x = 0; x < 8; x++)
	{
		for (size_t y = 0; y < 8; y++)
		{
			lauta[x][y] = nullptr;
		}
	}

	onkoMustaDTLiikkunut = false;
	onkoMustaKTLiikkunut = false;
	onkoValkeaDTLiikkunut = false;
	onkoValkeaKTLiikkunut = false;
	onkoValkeaKuningasLiikkunut = false;
	onkoMustaKuningasLiikkunut = false;
	
	//alusta valkoiset nappulat
	vs = new Sotilas(L"\u2659", 0, VS);
	vt = new Torni(L"\u2656", 0, VT);
	vr = new Ratsu(L"\u2658", 0, VR);
	vl = new Lahetti(L"\u2657", 0, VL);
	vk = new Kuningas(L"\u2654", 0 ,VK);
	vd = new Kuningatar(L"\u2655", 0 ,VD);

	//Aseta ne Asemaan
	for (size_t i = 0; i < 8; i++)
	{
		lauta[i][1] = vs;
	}
	
	lauta[0][0] = vt;
	lauta[1][0] = vr;
	lauta[2][0] = vl;
	lauta[3][0] = vk;
	lauta[4][0] = vd;
	lauta[5][0] = vl;
	lauta[6][0] = vr;
	lauta[7][0] = vt;

	//alusta mustat nappulat
	ms = new Sotilas(L"\u265F", 1, MS);
	mt = new Torni(L"\u265C", 1, MT);
	mr = new Ratsu(L"\u265E", 1, MR);
	ml = new Lahetti(L"\u265D", 1, ML);
	mk = new Kuningas(L"\u265A", 1, MK);
	md = new Kuningatar(L"\u265B", 1, MD);

	//Aseta ne Asemaan
	for (size_t i = 0; i < 8; i++)
	{
		lauta[i][6] = ms;
	}
	lauta[0][7] = mt;
	lauta[1][7] = mr;
	lauta[2][7] = ml;
	lauta[3][7] = mk;
	lauta[4][7] = md;
	lauta[5][7] = ml;
	lauta[6][7] = mr;
	lauta[7][7] = mt;
	
}

Ruutu Asema::EtsiKuningas(int vari)
{
	for (int y = 7; y >= 0; y--)
	{
		for (int x = 0; x < 8; x++)
		{
			if(lauta[x][y] != nullptr) 
			{
				if (lauta[x][y]->GetKoodi() == VK || lauta[x][y]->GetKoodi() == MK)
				{
					if (vari == lauta[x][y]->GetVari())
					{
						Ruutu pos(x, y);
						return pos;
					}
				}
			}
		}
	}
}

void Asema::PaivitaAsema(Siirto* siirto)
{

	//Ottaa siirron vastaan ja asettaa sen alkukoordinaatit ja kohdekoordinaatit apumuuttujiin.
	int x = siirto->GetAlkuRuutu().GetSarake();
	int y = siirto->GetAlkuRuutu().GetRivi();
	int tx = siirto->GetLoppuRuutu().GetSarake();
	int ty = siirto->GetLoppuRuutu().GetRivi();

	//Testaa minkä napin siirto on kyseessä, siirrettävän napin etumerkin perusteella
	switch (siirto->GetNappi())
	{
	case 'K':
		//std::wcout << "Valitsit Kuninkaan" << std::endl;

		if (siirto->OnkoLyhytLinna())
		{
			//siirto on lyhytlinna
			if (siirtovuoro == 0 && !GetOnkoValkeaKuningasLiikkunut() && !GetOnkoValkeaKTliikkunut()) {
				std::wcout << "Valkoinen lyhytlinna onnistui!" << std::endl;
				lauta[4][0] = nullptr;
				lauta[6][0] = vk;
				lauta[7][0] = nullptr;
				lauta[5][0] = vt;

				lauta[6][0]->onkoLiikkunut = true;
				lauta[5][0]->onkoLiikkunut = true;

			}
			else if (siirtovuoro == 1 && !GetOnkoMustaKuningasLiikkunut() && !GetOnkoMustaKTliikkunut())
			{
				std::wcout << "Musta lyhytlinna onnistui!" << std::endl;
				lauta[4][7] = nullptr;
				lauta[6][7] = mk;
				lauta[7][7] = nullptr;
				lauta[5][7] = mt;
				
				lauta[6][7]->onkoLiikkunut = true;
				lauta[5][7]->onkoLiikkunut = true;

			}
		}

		if (siirto->OnkoPitkaLinna())
		{
			//siirto on pitkälinna
			if (siirtovuoro == 0 && !GetOnkoValkeaKuningasLiikkunut() && GetOnkoValkeaDTliikkunut() && !GetOnkoValkeaKTliikkunut())
			{
				std::wcout << "Valkoinen pitkälinna onnistui!" << std::endl;

				lauta[4][0] = nullptr;
				lauta[2][0] = vk;
				lauta[0][0] = nullptr;
				lauta[3][0] = vt;

				lauta[2][0]->onkoLiikkunut = true;
				lauta[3][0]->onkoLiikkunut = true;
			}
			else if (siirtovuoro == 1 && !GetOnkoMustaKuningasLiikkunut() && !GetOnkoMustaKTliikkunut() && GetOnkoMustaDTliikkunut())
			{
				std::wcout << "Musta pitkälinna onnistui!" << std::endl;

				lauta[4][7] = nullptr;
				lauta[2][7] = mk;
				lauta[0][7] = nullptr;
				lauta[3][7] = mt;

				lauta[2][7]->onkoLiikkunut = true;
				lauta[3][7]->onkoLiikkunut = true;
			}
			
			if (!siirto->OnkoPitkaLinna() || !siirto->OnkoLyhytLinna())
			{
				lauta[tx][ty] = lauta[x][y];
				lauta[x][y] = nullptr;

				if (siirtovuoro == 0 && !lauta[tx][ty]->onkoLiikkunut)
				{
					lauta[tx][ty]->onkoLiikkunut = true;
					onkoValkeaKuningasLiikkunut = true;
				}
				else 
				{
					lauta[tx][ty]->onkoLiikkunut = true;
					onkoMustaKuningasLiikkunut = true;
				}
			}
		}

		break;

	case 'D':
		//std::wcout << "Valitsit Daamin" << std::endl;
		
		lauta[tx][ty] = lauta[x][y];
		lauta[x][y] = nullptr;
		
		if (siirtovuoro == 0 && !lauta[tx][ty]->onkoLiikkunut) 
		{
			lauta[tx][ty]->onkoLiikkunut = true;
			onkoValkeaDTLiikkunut = true;
		}
		else
		{
			lauta[tx][ty]->onkoLiikkunut = true;
			onkoMustaDTLiikkunut = true;
		}

		break;

	case 'L':
		//std::wcout << "Valitsit Lähetin" << std::endl;

		lauta[x][y]->onkoLiikkunut = true;
		lauta[tx][ty] = lauta[x][y];
		lauta[x][y] = nullptr;
		

		break;

	case 'R':
		//std::wcout << "Valitsit Ratsun" << std::endl;

		lauta[x][y]->onkoLiikkunut = true;
		lauta[tx][ty] = lauta[x][y];
		lauta[x][y] = nullptr;
	
		
		break;

	case 'T':
		//std::wcout << "Valitsit Tornin" << std::endl;

		lauta[tx][ty] = lauta[x][y];
		lauta[x][y] = nullptr;

		if (siirtovuoro == 0 && !lauta[tx][ty]->onkoLiikkunut)
		{
			lauta[tx][ty]->onkoLiikkunut = true;
			onkoValkeaKTLiikkunut = true;
		}
		else 
		{
			lauta[tx][ty]->onkoLiikkunut = true;
			onkoMustaKTLiikkunut = true;
		}

	case 'S':
		//std::wcout << "Valitsit Sotilaan" << std::endl;
		if (siirto->miksiKorotetaan != nullptr) 
		{
			lauta[tx][ty] = siirto->miksiKorotetaan;
			break;
		}
		if (lauta[x][y] != nullptr && lauta[x][y]->GetKoodi() == VS &&
			lauta[tx][ty] == nullptr && x != tx  ||
			lauta[x][y] != nullptr && lauta[x][y]->GetKoodi() == MS &&
			lauta[tx][ty] == nullptr && x != tx)
		{
			lauta[tx][y] = nullptr;
			break;
		}
	
		lauta[x][y]->onkoLiikkunut = true;
		lauta[tx][ty] = lauta[x][y];
		lauta[x][y] = nullptr;	
		

		break;

	default:
		std::wcout << "Valitsit jonkun random, en tiiä... Laita se etumerkki eteen" << std::endl;

		break;
	}

}

int Asema::GetSiirtovuoro()
{
	return siirtovuoro;
}

void Asema::SetSiirtovuoro(int vari)
{
	siirtovuoro = vari;
}

void Asema::AnnaLaillisetSiirrot(std::list<Siirto>& lista)
{
	//lista vastustajanSiirroille
	std::list<Siirto> vastustajanSiirrot;
	int vastustajanSiirtoVuoro= 0;

	//päätellään vastustajan siirtovuoro
	if (siirtovuoro == 0)
	{
		vastustajanSiirtoVuoro = siirtovuoro + 1;
	}
	else
	{
		vastustajanSiirtoVuoro = siirtovuoro -1;
	}

	//Etsitään oman kuninkaan ruutu
	Ruutu kuninkaanSijainti = EtsiKuningas(siirtovuoro);

	//Tee kopio nykyisestä asemasta
	Asema uusi;

	//Generoi vastustajan raakasiirrot
	
	AnnaRaakaSiirrot(lista, siirtovuoro);
	
	//Käydään läpi siirtoja, tee siirto uudessa asemassa 
	std::wcout << "KÄYDÄÄN LÄPI SIIRTOJA: " << std::endl;
	for (Siirto s : lista)
	{		
		uusi = *this;
		uusi.PaivitaAsema(&s);
		uusi.AnnaRaakaSiirrot(vastustajanSiirrot, vastustajanSiirtoVuoro);
		//testataan onko kuningas uhattu siirron jälkeen
		if (OnkoRuutuUhattu(kuninkaanSijainti, vastustajanSiirrot))
		{	
			lista.remove(s);	
		}	
	}

	//Tarkastetaan linnoitukset ja lisätään listaan
	if (siirtovuoro == 0) {
		//valkean lyhyt linna
		if (!GetOnkoValkeaKuningasLiikkunut() && !GetOnkoValkeaKTliikkunut()
			&& OnkoRuutuUhattu(Ruutu(4, 0), vastustajanSiirrot)
			&& OnkoRuutuUhattu(Ruutu(5, 0), vastustajanSiirrot) && OnkoRuutuUhattu(Ruutu(6, 0), vastustajanSiirrot)
			&& lauta[5][0] == nullptr && lauta[6][0] == nullptr) 
		{
			//päivitetään listaan lyhytlinna
			lista.push_back(Siirto(true, false,'K')); // lisätään listaan lyhyt linna
		}
		//valkean pitkä linna
		if (!GetOnkoValkeaKuningasLiikkunut() && !GetOnkoValkeaDTliikkunut()
			&& OnkoRuutuUhattu(Ruutu(4, 0), vastustajanSiirrot)
			&& OnkoRuutuUhattu(Ruutu(3, 0), vastustajanSiirrot) && OnkoRuutuUhattu(Ruutu(3, 0), vastustajanSiirrot)
			&& lauta[3][0] == nullptr && lauta[2][0] == nullptr) {
			//päivitetään listaan lyhytlinna
			lista.push_back(Siirto(false, true, 'K')); // lisätään listaan lyhyt linna
		}
	}
	if (siirtovuoro == 1) {
		//mustan lyhyt linna
		if (!GetOnkoMustaKuningasLiikkunut() && !GetOnkoMustaKTliikkunut()
			&& OnkoRuutuUhattu(Ruutu(4, 7), vastustajanSiirrot)
			&& OnkoRuutuUhattu(Ruutu(5, 7), vastustajanSiirrot) && OnkoRuutuUhattu(Ruutu(6, 7), vastustajanSiirrot)
			&& lauta[5][7] == nullptr && lauta[6][7] == nullptr) {
			//päivitetään listaan lyhytlinna
			lista.push_back(Siirto(true, false, 'K')); // lisätään listaan lyhyt linna
		}
		//mustan pitkä linna
		if (!GetOnkoMustaKuningasLiikkunut() && !GetOnkoMustaDTliikkunut()
			&& OnkoRuutuUhattu(Ruutu(4, 7), vastustajanSiirrot)
			&& OnkoRuutuUhattu(Ruutu(3, 7), vastustajanSiirrot) && OnkoRuutuUhattu(Ruutu(3, 7), vastustajanSiirrot)
			&& lauta[3][7] == nullptr && lauta[2][7] == nullptr) {
			//päivitetään listaan lyhytlinna
			lista.push_back(Siirto(false, true, 'K')); // lisätään listaan lyhyt linna
		}
	}

	//tulosta vielä kaikki laillisetsiirrot
	for (Siirto s : lista)
	{
		
		s.TulostaRuudut();
		
	}
}

void Asema::AnnaRaakaSiirrot(std::list<Siirto>& lista, int vari)
{

	for (int y = 7; y >= 0; y--)
	{
		for (int x = 0; x < 8; x++)
		{
			//käydään lauta läpi ja katsotaan onko nappula siirtovuorossa olevan nappula
			if (lauta[x][y] != nullptr && lauta[x][y]->GetVari() == vari)
			{

				Ruutu pos(x, y);
				//std::wcout << "alkuPosX : " << x << " alkuPosY : " << y << std::endl;
				//std::wcout << "Väri:" << lauta[x][y]->GetVari() << " enum:" << lauta[x][y]->GetKoodi() << " " << lauta[x][y]->GetUnicode() << std::endl;
				lauta[x][y]->AnnaSiirrot(lista, &pos, this, lauta[x][y]->GetVari());

			}
		}
	}
}

bool Asema::GetOnkoValkeaKuningasLiikkunut()
{
	if (onkoValkeaKuningasLiikkunut) {
		return true;
	}
	return false;
}

bool Asema::GetOnkoMustaKuningasLiikkunut()
{
	if (onkoMustaKuningasLiikkunut) {
		return true;
	}
	return false;
}

bool Asema::GetOnkoValkeaDTliikkunut()
{
	if (onkoValkeaDTLiikkunut) {
		return true;
	}
	return false;
}

bool Asema::GetOnkoValkeaKTliikkunut()
{
	if (onkoValkeaKTLiikkunut) {
		return true;
	}
	return false;
}

bool Asema::GetOnkoMustaDTliikkunut()
{
	if (onkoMustaDTLiikkunut) {
		return true;
	}
	return false;
}

bool Asema::GetOnkoMustaKTliikkunut()
{
	if (onkoMustaKTLiikkunut) {
		return true;
	}
	return false;
}

bool Asema::OnkoRuutuUhattu(Ruutu ruutu, std::list<Siirto>& siirrot)
{

	//käydään siirtoja läpi ja testaillaan loppuruutuja, että osuuko parametrin ruutuun.
	for (Siirto s : siirrot)
	{
		//Selkeyttääkseni käytän target x ja target y
		int tx = s.GetLoppuRuutu().GetSarake();
		int ty = s.GetLoppuRuutu().GetRivi();

		//Siirto on sotilaan! Tarkastetaan poikkeukset
		if (s.GetNappi() == 'S') 
		{
			int x = s.GetAlkuRuutu().GetSarake();
			int y = s.GetAlkuRuutu().GetRivi();

			//sotilas on uhkaamassa ruutua viistoon.
			//virhe..
			if (tx == x + 1 && ruutu.GetSarake() == tx && ruutu.GetRivi() == ty && siirtovuoro == 1 || 
				tx == x - 1 && ruutu.GetSarake() == tx && ruutu.GetRivi() == ty && siirtovuoro == 0)
			{
				std::wcout << "Sotilas uhkaa ruutua! XY:" << ruutu.GetSarake() << ruutu.GetRivi() << std::endl;
				return true;
			}
			//jos sotilas vain liikkuu niin ei uhkaa ruutua, koska sotilas ei osaa syödä eteen.
			else 
			{
				continue;
			}
		}
		//Siirto ei ole sotilaan
		else 
		{
			//Uhkaa ruutua
			if (tx == ruutu.GetSarake() && ty == ruutu.GetRivi()) 
			{
				std::wcout << "Joku uhkaa ruutua! XY:" << ruutu.GetSarake() << ruutu.GetRivi() << std::endl;
				return true;
			}

		}
	}

	return false;

}
