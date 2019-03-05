#include "Asema.h"

Nappula* Asema::vk = new Kuningas(L"\u2654", 0, VK);
Nappula* Asema::vd = new Kuningatar(L"\u2655", 0, VD);
Nappula* Asema::vt = new Torni(L"\u2656", 0, VT);
Nappula* Asema::vl = new Lahetti(L"\u2657", 0, VL);
Nappula* Asema::vr = new Ratsu(L"\u2658", 0, VR);
Nappula* Asema::vs = new Sotilas(L"\u2659", 0, VS);

Nappula* Asema::mk = new Kuningas(L"\u265A", 1, MK);
Nappula* Asema::md = new Kuningatar(L"\u265B", 1, MD);
Nappula* Asema::mt = new Torni(L"\u265C", 1, MT);
Nappula* Asema::ml = new Lahetti(L"\u265D", 1, ML);
Nappula* Asema::mr = new Ratsu(L"\u265E", 1, MR);
Nappula* Asema::ms = new Sotilas(L"\u265F", 1, MS);

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

	// Kaksoisaskel-lippu on oletusarvoisesti pois päältä.
	// Asetetaan myöhemmin, jos tarvii.
	this->kaksoisaskelSarakkeella = -1;

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
				
				lauta[4][0] = nullptr;
				lauta[6][0] = vk;
				lauta[7][0] = nullptr;
				lauta[5][0] = vt;
		
				onkoValkeaKuningasLiikkunut = true;

			}
			else if (siirtovuoro == 1 && !GetOnkoMustaKuningasLiikkunut() && !GetOnkoMustaKTliikkunut())
			{
				
				lauta[4][7] = nullptr;
				lauta[6][7] = mk;
				lauta[7][7] = nullptr;
				lauta[5][7] = mt;
						
				onkoMustaKuningasLiikkunut = true;

			}
		}

		if (siirto->OnkoPitkaLinna())
		{
			//siirto on pitkälinna
			if (siirtovuoro == 0 && !GetOnkoValkeaKuningasLiikkunut() && GetOnkoValkeaDTliikkunut() && !GetOnkoValkeaKTliikkunut())
			{
				
				lauta[4][0] = nullptr;
				lauta[2][0] = vk;
				lauta[0][0] = nullptr;
				lauta[3][0] = vt;

				onkoValkeaKuningasLiikkunut = true;
			}
			else if (siirtovuoro == 1 && !GetOnkoMustaKuningasLiikkunut() && !GetOnkoMustaKTliikkunut() && GetOnkoMustaDTliikkunut())
			{
			
				lauta[4][7] = nullptr;
				lauta[2][7] = mk;
				lauta[0][7] = nullptr;
				lauta[3][7] = mt;

				onkoMustaKuningasLiikkunut = true;
			}
		}

		lauta[tx][ty] = lauta[x][y];
		lauta[x][y] = nullptr;

		if (siirtovuoro == 0 && !GetOnkoValkeaKTliikkunut())
		{

			onkoValkeaKuningasLiikkunut = true;

		}
		else if (siirtovuoro == 1 && !GetOnkoMustaKuningasLiikkunut())
		{

			onkoMustaKuningasLiikkunut = true;

		}
		
		break;

	case 'D':
		//std::wcout << "Valitsit Daamin" << std::endl;
		
		lauta[tx][ty] = lauta[x][y];
		lauta[x][y] = nullptr;
		
		if (siirtovuoro == 0 && !GetOnkoValkeaDTliikkunut()) 
		{
			
			onkoValkeaDTLiikkunut = true;

		}
		else if(siirtovuoro == 1 && !GetOnkoMustaDTliikkunut())
		{
		
			onkoMustaDTLiikkunut = true;
		}

		break;

	case 'L':
		//std::wcout << "Valitsit Lähetin" << std::endl;

		lauta[tx][ty] = lauta[x][y];
		lauta[x][y] = nullptr;
		
		break;

	case 'R':
		//std::wcout << "Valitsit Ratsun" << std::endl;

		lauta[tx][ty] = lauta[x][y];
		lauta[x][y] = nullptr;
	
		break;

	case 'T':
		//std::wcout << "Valitsit Tornin" << std::endl;

		lauta[tx][ty] = lauta[x][y];
		lauta[x][y] = nullptr;

		if (siirtovuoro == 0 && !GetOnkoValkeaKTliikkunut())
		{
			onkoValkeaKTLiikkunut = true;
		}
		else if (siirtovuoro == 1 && !GetOnkoMustaKTliikkunut())
		{
			onkoMustaKTLiikkunut = true;
		}

		break;

	case 'S':
		//std::wcout << "Valitsit Sotilaan" << std::endl;
		if (siirto->miksiKorotetaan != nullptr) 
		{
			lauta[tx][ty] = siirto->miksiKorotetaan;
			lauta[x][y] = nullptr;
			break;
		}
		// Tarkistetaan oliko sotilaan kaksoisaskel
		// (asetetaan kaksoisaskel-lippu)
		if
			((lauta[x][y]->GetKoodi() == VS || lauta[x][y]->GetKoodi() == MS) &&
				(y - ty == 2 || y - ty == -2))
		{
			kaksoisaskelSarakkeella = x;
		}
		if (lauta[x][y] != nullptr && lauta[x][y]->GetKoodi() == VS &&
			lauta[tx][ty] == nullptr && x != tx  ||
			lauta[x][y] != nullptr && lauta[x][y]->GetKoodi() == MS &&
			lauta[tx][ty] == nullptr && x != tx)
		{
			lauta[tx][y] = nullptr;
			break;
		}
		if (lauta[x][y] != nullptr && lauta[x][y]->GetKoodi() == VS || 
			lauta[x][y] != nullptr && lauta[x][y]->GetKoodi() == MS)
		{
			//lauta[x][y]->SetOnkoLiikkunut(true);
		}
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
	AnnaRaakaSiirrot(lista, siirtovuoro);
	AnnaLinnoitusSiirrot(lista);
	KuninkaanShakit(lista);

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

void Asema::TestaaLiiike(Siirto * s)
{

	int x = s->GetAlkuRuutu().GetSarake();
	int y = s->GetAlkuRuutu().GetRivi();
	int tx = s->GetLoppuRuutu().GetSarake();
	int ty = s->GetLoppuRuutu().GetRivi();

	lauta[tx][ty] = lauta[x][y];
	lauta[x][y] = nullptr;

}

void Asema::AnnaLinnoitusSiirrot(std::list<Siirto>& lista)
{
	//Tarkastetaan linnoitukset ja lisätään listaan
	if (siirtovuoro == 0) {
		//valkean lyhyt linna
		if (!GetOnkoValkeaKuningasLiikkunut() && !GetOnkoValkeaKTliikkunut()
			&& OnkoRuutuUhattu(&Ruutu(4, 0), lista)
			&& OnkoRuutuUhattu(&Ruutu(5, 0), lista) && OnkoRuutuUhattu(&Ruutu(6, 0), lista)
			&& lauta[5][0] == nullptr && lauta[6][0] == nullptr)
		{
			//päivitetään listaan lyhytlinna
			lista.push_back(Siirto(true, false, 'K')); // lisätään listaan lyhyt linna
		}
		//valkean pitkä linna
		if (!GetOnkoValkeaKuningasLiikkunut() && !GetOnkoValkeaDTliikkunut()
			&& OnkoRuutuUhattu(&Ruutu(4, 0), lista)
			&& OnkoRuutuUhattu(&Ruutu(3, 0), lista) && OnkoRuutuUhattu(&Ruutu(3, 0), lista)
			&& lauta[3][0] == nullptr && lauta[2][0] == nullptr) {
			//päivitetään listaan lyhytlinna
			lista.push_back(Siirto(false, true, 'K')); // lisätään listaan lyhyt linna
		}
	}
	if (siirtovuoro == 1) {
		//mustan lyhyt linna
		if (!GetOnkoMustaKuningasLiikkunut() && !GetOnkoMustaKTliikkunut()
			&& OnkoRuutuUhattu(&Ruutu(4, 7), lista)
			&& OnkoRuutuUhattu(&Ruutu(5, 7), lista) && OnkoRuutuUhattu(&Ruutu(6, 7), lista)
			&& lauta[5][7] == nullptr && lauta[6][7] == nullptr) {
			//päivitetään listaan lyhytlinna
			lista.push_back(Siirto(true, false, 'K')); // lisätään listaan lyhyt linna
		}
		//mustan pitkä linna
		if (!GetOnkoMustaKuningasLiikkunut() && !GetOnkoMustaDTliikkunut()
			&& OnkoRuutuUhattu(&Ruutu(4, 7), lista)
			&& OnkoRuutuUhattu(&Ruutu(3, 7), lista) && OnkoRuutuUhattu(&Ruutu(3, 7), lista)
			&& lauta[3][7] == nullptr && lauta[2][7] == nullptr) {
			//päivitetään listaan lyhytlinna
			lista.push_back(Siirto(false, true, 'K')); // lisätään listaan lyhyt linna
		}
	}
}

void Asema::KuninkaanShakit(std::list<Siirto>& lista)
{

	//lista vastustajanSiirroille
	std::list<Siirto> vastustajanSiirrot;
	//siivotutSiirrot
	std::list<Siirto> siivotutSiirrot;
	int vastustajanSiirtoVuoro = 0;
	Ruutu kuninkaanSijainti;
	Asema testiAsema;

	//Katsotaan vuoro
	if (siirtovuoro == 0)
	{
		kuninkaanSijainti = EtsiKuningas(siirtovuoro);
		vastustajanSiirtoVuoro = siirtovuoro + 1;
	}
	else
	{
		kuninkaanSijainti = EtsiKuningas(siirtovuoro);
		vastustajanSiirtoVuoro = siirtovuoro - 1;
	}

	for (Siirto s : lista)
	{
		testiAsema = *this;
		testiAsema.PaivitaAsema(&s);
		int x, y;

		if (s.OnkoLyhytLinna())
		{
			x = 6;

			if (siirtovuoro == 0) 
			{
				y = 0;
			}
			else
			{
				y = 7;
			}
		}
		else if (s.OnkoPitkaLinna()) 
		{
			x = 2;
			
			if (siirtovuoro == 0) 
			{
				y = 0;
			}
			else 
			{
				y = 7;
			}

		}
		else 
		{
		
			Nappula* siirtyva = lauta[s.GetAlkuRuutu().GetSarake()][s.GetAlkuRuutu().GetRivi()];

			if (siirtyva->GetKoodi() == VK || siirtyva->GetKoodi() == MK) 
			{
				x = s.GetLoppuRuutu().GetSarake();
				y = s.GetLoppuRuutu().GetRivi();
			}
			else 
			{
				x = kuninkaanSijainti.GetSarake();
				y = kuninkaanSijainti.GetRivi();
			}
		}

		testiAsema.AnnaRaakaSiirrot(vastustajanSiirrot, vastustajanSiirtoVuoro);

		Ruutu kuningasPaikka(x, y);

		
		if (testiAsema.OnkoRuutuUhattu(&kuningasPaikka, vastustajanSiirrot) == false)
		{
			siivotutSiirrot.push_back(s);
		}
	
	}

	lista = siivotutSiirrot;

}

double Asema::LoppuTulos()
{
	double loppuTulos = 0;
	
	Ruutu kuninkaanSijainti = EtsiKuningas(siirtovuoro);
	bool shakkiMatti = false;

	std::list<Siirto>vastustajanSiirrot;

	if (siirtovuoro == 0)
	{
		AnnaRaakaSiirrot(vastustajanSiirrot, 1);
	}
	else 
	{
		AnnaRaakaSiirrot(vastustajanSiirrot, 0);
	}

	shakkiMatti = OnkoRuutuUhattu(&kuninkaanSijainti, vastustajanSiirrot);

	//jos kyseessä on shakkimatti
	if (shakkiMatti) {
		if (siirtovuoro == 0)
		{
			loppuTulos = 1000000;
		}
		else
		{
			loppuTulos = -1000000;
		}
	}
	else 
	{
		return 0;
	}
	
	return loppuTulos;
}

double Max(double& val1, double& val2) 
{
	if (val1 > val2) 
	{
		return val1;
	} 
	return val2;
}

double Min(double& val1, double& val2)
{
	if (val1 <= val2)
	{
		return val1;
	}
	return val2;
}


MinMaxPaluu Asema::MiniMax(int syvyys, double alpha, double beta)
{

	MinMaxPaluu paluu;
	std::list<Siirto> siirrot;
	AnnaLaillisetSiirrot(siirrot);

	//Ei ole mahdollisia siirtoja, katsotaan mikä on pelin lopputulos palautetaan arvo
	if (siirrot.size() == 0)
	{
		paluu.evaluointiArvo = LoppuTulos();
		return paluu;
	}
	//Ollaan tutkittu puuta haluttuun syvyyteen asti, evaluoidaan seuraava järkevä siirto laskemalla
	if (syvyys == 0)
	{
		paluu.evaluointiArvo = Evaluoi();
		return paluu;
	}

	if (siirtovuoro == 0)
	{
		paluu.evaluointiArvo = -INFINITY;
		//Tutkii jokaista siirtoa seuraavassa asemassa
		for (Siirto s : siirrot)
		{

			Asema uusi = *this;
			uusi.PaivitaAsema(&s);

			//laskee arvoja siirroille kunnes ollaan riittävän syvällä
			MinMaxPaluu arvo = uusi.MiniMax(syvyys - 1, alpha, beta);

			//Katsoo onko siirron arvo suurempi / pienempi vuorosta riippuen alku arvoon verrattuna
			if (arvo.evaluointiArvo > paluu.evaluointiArvo) 
			{
				paluu.evaluointiArvo = arvo.evaluointiArvo;
				paluu.parasSiirto = s;
			}
			if (paluu.evaluointiArvo > alpha) 
			{
				alpha = paluu.evaluointiArvo;
			}
			if (beta <= alpha)
			{
				break;
			}
		}
		return paluu;
	}
	else 
	{
		paluu.evaluointiArvo = +INFINITY;

		//Tutkii jokaista siirtoa seuraavassa asemassa
		for (Siirto s : siirrot)
		{

			Asema uusi = *this;
			uusi.PaivitaAsema(&s);

			//laskee arvoja siirroille kunnes ollaan riittävän syvällä
			MinMaxPaluu arvo = uusi.MiniMax(syvyys - 1, alpha, beta);

			//Katsoo onko siirron arvo suurempi / pienempi vuorosta riippuen alku arvoon verrattuna
			if (arvo.evaluointiArvo < paluu.evaluointiArvo) 
			{
				paluu.evaluointiArvo = arvo.evaluointiArvo;
				paluu.parasSiirto = s;
			}
			if (paluu.evaluointiArvo < beta) 
			{
				beta = paluu.evaluointiArvo;
			}

			if (beta <= alpha)
			{
				break;
			}
		}
		return paluu;
	}
	
}

double Asema::Evaluoi()
{

	double summa = 0;
	double materiaaliKerroin = 0.8;
	//jos haluaa tuunata
	double muuKerroin = 0.2;

	//MATERIAALI
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			if (lauta[x][y] == nullptr) 
			{
				continue;
			}
			else
			{
				switch (lauta[x][y]->GetKoodi())
				{
					//Valkoiset
				case VS:
					summa += sotilaanArvo;
					break;
				case VT:
					summa += torninArvo;
					break;
				case VR:
					summa += ratsunArvo;
					break;
				case VL:
					summa += lahetinArvo;
					break;
				case VK:
					//Kuninkaan kohdalla ei mittää
					break;
				case VD:
					summa += kuningattarenArvo;
					break;
					//Mustat
				case MS:
					summa -= sotilaanArvo;
					break;
				case MT:
					summa -= torninArvo;
					break;
				case MR:
					summa -= ratsunArvo;
					break;
				case ML:
					summa -= lahetinArvo;
					break;
				case MK:
					//Kuninkaan kohdalla ei mittää
					break;
				case MD:
					summa -= kuningattarenArvo;
					break;			

				default:
					break;
				}
			}
		}
	}
	
	return summa * materiaaliKerroin;
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

bool Asema::OnkoRuutuUhattu(Ruutu* ruutu, std::list<Siirto>& siirrot)
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
			if (tx == x + 1 && ruutu->GetSarake() == tx && ruutu->GetRivi() == ty && siirtovuoro == 1 ||
				tx == x - 1 && ruutu->GetSarake() == tx && ruutu->GetRivi() == ty && siirtovuoro == 0)
			{
				//std::wcout << "Sotilas uhkaa ruutua! XY:" << ruutu->GetSarake() << ruutu->GetRivi() << std::endl;
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
			if (tx == ruutu->GetSarake() && ty == ruutu->GetRivi())
			{
				//std::wcout << "Joku uhkaa ruutua! XY:" << ruutu->GetSarake() << ruutu->GetRivi() << std::endl;
				return true;
			}

		}
	}

	return false;

}
