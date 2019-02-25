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

	//Alusta valkoiset nappulat
	/*
	for (size_t i = 0; i < 8; i++)
	{
		lauta[6][i] = new Sotilas(L"\u2659", 0, VS);
	}

	lauta[7][0] = new Torni(L"\u2656", 0, VT);
	lauta[7][1] = new Ratsu(L"\u2658", 0, VR);
	lauta[7][2] = new Lahetti(L"\u2657", 0, VL);
	lauta[7][3] = new Kuningatar(L"\u2655", 0, VD);
	lauta[7][4] = new Kuningas(L"\u2654", 0, VK);
	lauta[7][5] = new Lahetti(L"\u2656", 0, VL);
	lauta[7][6] = new Ratsu(L"\u2658", 0, VR);
	lauta[7][7] = new Torni(L"\u2656", 0, VT);

	//Alusta mustat nappulat
	for (size_t i = 0; i < 8; i++)
	{
		lauta[1][i] = new Sotilas(L"\u265F", 1, MS);
	}

	lauta[0][0] = new Torni(L"\u265C", 1, MT);
	lauta[0][1] = new Ratsu(L"\u265E", 1, MR);
	lauta[0][2] = new Lahetti(L"\u265D", 1, ML);
	lauta[0][3] = new Kuningatar(L"\u265B", 1, MD);
	lauta[0][4] = new Kuningas(L"\u265A", 1, MK);
	lauta[0][5] = new Lahetti(L"\u265D", 1, ML);
	lauta[0][6] = new Ratsu(L"\u265E", 1, MR);
	lauta[0][7] = new Torni(L"\u265C", 1, MT);
	*/

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
	std::list<Siirto> siirtoLista;

	//Testaa minkä napin siirto on kyseessä
	switch (siirto->GetNappi())
	{
	case 'K':
		std::wcout << "Valitsit Kuninkaan" << std::endl;

		if (siirto->OnkoLyhytLinna() == true)
		{
			//siirto on lyhytlinna
			if (siirtovuoro == 0 && !GetOnkoValkeaKuningasLiikkunut() && !GetOnkoValkeaKTliikkunut()) {
				std::wcout << "Valkoinen lyhytlinna onnistui!" << std::endl;

				lauta[4][0] = nullptr; 
				lauta[6][0] = vk; 
				lauta[7][0] = nullptr; 
				lauta[5][0] = vt;

			}
			else if (siirtovuoro == 1 && !GetOnkoMustaKuningasLiikkunut() && !GetOnkoMustaKTliikkunut())
			{
				std::wcout << "Musta lyhytlinna onnistui!" << std::endl;

				lauta[4][7] = nullptr; 
				lauta[6][7] = mk; 
				lauta[7][7] = nullptr;
				lauta[5][7] = mt; 

			}
			else {
				std::wcout << "Lyhytlinna ei onnistunut!" << std::endl;
				
			}
		}

		if (siirto->OnkoPitkaLinna() == true)
		{
			//siirto on pitkälinna
			if (siirtovuoro == 0 && !GetOnkoValkeaKuningasLiikkunut() && GetOnkoValkeaDTliikkunut() && !GetOnkoValkeaKTliikkunut()) {
				std::wcout << "Valkoinen pitkälinna onnistui!" << std::endl;

				lauta[4][0] = nullptr; 
				lauta[2][0] = vk;
				lauta[0][0] = nullptr;
				lauta[3][0] = vt;
			}
			else if (siirtovuoro == 1 && !GetOnkoMustaKuningasLiikkunut() && !GetOnkoMustaKTliikkunut() && GetOnkoMustaDTliikkunut()) {
				std::wcout << "Musta pitkälinna onnistui!" << std::endl;

				lauta[4][7] = nullptr;
				lauta[2][7] = mk;
				lauta[0][7] = nullptr;
				lauta[3][7] = mt;

			}
			else {
				std::wcout << "Pitkälinna ei onnistunut!" << std::endl;
				
			}
		}

		if (siirtovuoro == 0) 
		{

			AnnaLaillisetSiirrot(siirtoLista);

			onkoValkeaKuningasLiikkunut = true;
		}
		else {

			AnnaLaillisetSiirrot(siirtoLista);

			onkoMustaKuningasLiikkunut = true;
		}

		break;

	case 'D':
		std::wcout << "Valitsit Daamin" << std::endl;

		if (siirtovuoro == 0) {

			AnnaLaillisetSiirrot(siirtoLista);

			onkoValkeaDTLiikkunut = true;
		}
		else {

			AnnaLaillisetSiirrot(siirtoLista);

			onkoMustaDTLiikkunut = true;
		}
		break;
	case 'L':
		std::wcout << "Valitsit Lähetin" << std::endl;

		if (siirtovuoro == 0) {

			AnnaLaillisetSiirrot(siirtoLista);

		}
		else {

			AnnaLaillisetSiirrot(siirtoLista);

		}
		break;
	case 'R':
		std::wcout << "Valitsit Ratsun" << std::endl;

		if (siirtovuoro == 0) {
		
			AnnaLaillisetSiirrot(siirtoLista);

		}
		else {

			AnnaLaillisetSiirrot(siirtoLista);

		}
		break;
	case 'T':
		std::wcout << "Valitsit Tornin" << std::endl;

		

		if (siirtovuoro == 0) {

			AnnaLaillisetSiirrot(siirtoLista);

			onkoValkeaKTLiikkunut = true;

		}
		else {

			AnnaLaillisetSiirrot(siirtoLista);

			onkoMustaKTLiikkunut = true;
		}
		break;
	case 'S':
		std::wcout << "Valitsit Sotilaan" << std::endl;

		

		if (siirtovuoro == 0) {
		
			AnnaLaillisetSiirrot(siirtoLista);

		}
		else {
		
			AnnaLaillisetSiirrot(siirtoLista);

		}
		break;
	default:
		std::wcout << "Valitsit jonkun random, en tiiä... Laita se etumerkki eteen" << std::endl;
		
		break;
	}

	for (Siirto s : siirtoLista)
	{
		int x = s.GetAlkuRuutu().GetSarake();
		int y = s.GetAlkuRuutu().GetRivi();
		int tx = s.GetLoppuRuutu().GetSarake();
		int ty = s.GetLoppuRuutu().GetRivi();

		if (siirto->GetAlkuRuutu() == s.GetAlkuRuutu() && siirto->GetLoppuRuutu() == s.GetLoppuRuutu())
		{		
			lauta[x][y]->onkoLiikkunut = true;
			lauta[s.GetLoppuRuutu().GetSarake()][s.GetLoppuRuutu().GetRivi()] = lauta[s.GetAlkuRuutu().GetSarake()][s.GetAlkuRuutu().GetRivi()];
			lauta[s.GetAlkuRuutu().GetSarake()][s.GetAlkuRuutu().GetRivi()] = nullptr;	
				
		}
	}

	if (siirtovuoro == 0) {
		std::wcout << "Seuraava siirtovuoro on mustan." << std::endl;
		siirtovuoro++;
	}
	else {
		std::wcout << "Seuraava siirtovuoro on valkoisen." << std::endl;
		siirtovuoro--;
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
	
	AnnaRaakaSiirrot(lista);

	Ruutu kuninkaanSijainti = EtsiKuningas(siirtovuoro);

	//Tee kopio nykyisestä asemasta
	Asema a;
	Asema uusi;
	uusi = a;
	uusi = *this;

	std::list<Siirto> laillisetSiirrot;

	//Käydään läpi siirtoja, tee siirto uudessa asemassa
	std::wcout << "KÄYDÄÄN LÄPI SIIRTOJA: " << std::endl;
	
	for (Siirto s : lista)
	{		
		
		uusi.lauta[s.GetLoppuRuutu().GetSarake()][s.GetLoppuRuutu().GetRivi()] = uusi.lauta[s.GetAlkuRuutu().GetSarake()][s.GetAlkuRuutu().GetRivi()];
		uusi.lauta[s.GetAlkuRuutu().GetSarake()][s.GetAlkuRuutu().GetRivi()] = nullptr;

		//Generoi uuden aseman raakasiirrot
		uusi.AnnaRaakaSiirrot(laillisetSiirrot);

		if (OnkoRuutuUhattu(kuninkaanSijainti, laillisetSiirrot))
		{	
			lista.remove(s);	
		}
		
	}
	//tulosta vielä kaikki laillisetsiirrot
	for (Siirto s : lista)
	{
		
		s.TulostaRuudut();
		
	}
}

void Asema::AnnaRaakaSiirrot(std::list<Siirto>& lista)
{

	for (int y = 7; y >= 0; y--)
	{
		for (int x = 0; x < 8; x++)
		{
			//käydään lauta läpi ja katsotaan onko nappula siirtovuorossa olevan nappula
			if (lauta[x][y] != nullptr && lauta[x][y]->GetVari() == siirtovuoro)
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
			if (tx == x + 1 && ruutu.GetSarake() == tx && ruutu.GetRivi() == ty || 
				tx == x - 1 && ruutu.GetSarake() == tx && ruutu.GetRivi() == ty )
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

	std::wcout << "EI UHKAA RUUTUA!" << std::endl;

	return false;

}
