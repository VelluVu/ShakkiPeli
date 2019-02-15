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


Asema::~Asema()
{

	//Vanha malli

	//Tyhjää kaikki muistipaikat
	delete mk, md, vk, vd, vt, vr, vl, mt, mr, ml, vs, ms;

	// Tyhjää paikat ja nullaa...
	for (size_t x = 0; x < 8; x++)
	{
		for (size_t y = 0; y < 8; y++)
		{
			delete [] lauta[x][y];
		}
	}	
}

Ruutu Asema::EtsiKuningas(int vari)
{
	for (int y = 7; y >= 0; y--)
	{
		for (int x = 0; x < 8; x++)
		{
			if (lauta[x][y]->GetKoodi() == VK || lauta[x][y]->GetKoodi() == MK) 
			{
				if (vari == lauta[x][y]->GetVari()) 
				{
					Ruutu pos(x,y);
					return pos;
				}
			}
		}
	}
}

void Asema::PaivitaAsema(Siirto* siirto)
{
	//Näin pääset siirtoon ja ruutuihin käsiksi...

	std::list<Siirto> laillisetSiirrot;
	
	
	//Testataan siirtoa
	//siirrä nappulaa ilman ihmellisempää jos loppupaikka on tyhjä
	/*
	if (siirto->OnkoLyhytLinna() == false && siirto->OnkoPitkaLinna() == false) {
		if (lauta[siirto->GetLoppuRuutu().GetRivi()][siirto->GetLoppuRuutu().GetSarake()] == nullptr) {
			lauta[siirto->GetLoppuRuutu().GetRivi()][siirto->GetLoppuRuutu().GetSarake()] = lauta[siirto->GetAlkuRuutu().GetRivi()][siirto->GetAlkuRuutu().GetSarake()];
			lauta[siirto->GetAlkuRuutu().GetRivi()][siirto->GetAlkuRuutu().GetSarake()] = nullptr;
		}
		else if (lauta[siirto->GetLoppuRuutu().GetRivi()][siirto->GetLoppuRuutu().GetSarake()]->GetVari() != siirtovuoro) {
			//jos vihu nii syöpoes...
			lauta[siirto->GetLoppuRuutu().GetRivi()][siirto->GetLoppuRuutu().GetSarake()] = nullptr;
			lauta[siirto->GetLoppuRuutu().GetRivi()][siirto->GetLoppuRuutu().GetSarake()] = lauta[siirto->GetAlkuRuutu().GetRivi()][siirto->GetAlkuRuutu().GetSarake()];
			lauta[siirto->GetAlkuRuutu().GetRivi()][siirto->GetAlkuRuutu().GetSarake()] = nullptr;
		}
		else if (lauta[siirto->GetLoppuRuutu().GetRivi()][siirto->GetLoppuRuutu().GetSarake()]->GetVari() == siirtovuoro) {
			//ei voi liikkua oman päälle
		}
	}
	*/

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
			

			}
			else if (siirtovuoro == 1 && !GetOnkoMustaKuningasLiikkunut() && !GetOnkoMustaKTliikkunut())
			{
				std::wcout << "Musta lyhytlinna onnistui!" << std::endl;

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

			}
			else if (siirtovuoro == 1 && !GetOnkoMustaKuningasLiikkunut() && !GetOnkoMustaKTliikkunut() && GetOnkoMustaDTliikkunut()) {
				std::wcout << "Musta pitkälinna onnistui!" << std::endl;

			}
			else {
				std::wcout << "Pitkälinna ei onnistunut!" << std::endl;
				
			}
		}

		if (siirtovuoro == 0) 
		{

			AnnaLaillisetSiirrot(laillisetSiirrot);
			for (Siirto n : laillisetSiirrot)
			{
				n.TulostaRuudut();
			}
			std::wcout << std::endl;

			onkoValkeaKuningasLiikkunut = true;
		}
		else {

			AnnaLaillisetSiirrot(laillisetSiirrot);
			for (Siirto n : laillisetSiirrot)
			{
				n.TulostaRuudut();
			}
			std::wcout << std::endl;

			onkoMustaKuningasLiikkunut = true;
		}

		break;

	case 'D':
		std::wcout << "Valitsit Daamin" << std::endl;

		if (siirtovuoro == 0) {

			AnnaLaillisetSiirrot(laillisetSiirrot);
			for (Siirto n : laillisetSiirrot)
			{
				n.TulostaRuudut();
			}
			std::wcout << std::endl;

			onkoValkeaDTLiikkunut = true;
		}
		else {

			AnnaLaillisetSiirrot(laillisetSiirrot);
			for (Siirto n : laillisetSiirrot)
			{
				n.TulostaRuudut();
			}
			std::wcout << std::endl;

			onkoMustaDTLiikkunut = true;
		}
		break;
	case 'L':
		std::wcout << "Valitsit Lähetin" << std::endl;

		if (siirtovuoro == 0) {

			AnnaLaillisetSiirrot(laillisetSiirrot);
			for (Siirto n : laillisetSiirrot)
			{
				n.TulostaRuudut();
			}
			std::wcout << std::endl;
			
		}
		else {

			AnnaLaillisetSiirrot(laillisetSiirrot);
			for (Siirto n : laillisetSiirrot)
			{
				n.TulostaRuudut();
			}
			std::wcout << std::endl;
		
		}
		break;
	case 'R':
		std::wcout << "Valitsit Ratsun" << std::endl;

		if (siirtovuoro == 0) {
		
			AnnaLaillisetSiirrot(laillisetSiirrot);
			for (Siirto n : laillisetSiirrot)
			{
				n.TulostaRuudut();
			}
			std::wcout << std::endl;

		}
		else {

			AnnaLaillisetSiirrot(laillisetSiirrot);
			for (Siirto n : laillisetSiirrot)
			{
				n.TulostaRuudut();
			}
			std::wcout << std::endl;
			
		}
		break;
	case 'T':
		std::wcout << "Valitsit Tornin" << std::endl;

		

		if (siirtovuoro == 0) {

			AnnaLaillisetSiirrot(laillisetSiirrot);
			for (Siirto n : laillisetSiirrot)
			{
				n.TulostaRuudut();
			}
			std::wcout << std::endl;

			onkoValkeaKTLiikkunut = true;

		}
		else {

			AnnaLaillisetSiirrot(laillisetSiirrot);
			for (Siirto n : laillisetSiirrot)
			{
				n.TulostaRuudut();
			}
			std::wcout << std::endl;

			onkoMustaKTLiikkunut = true;
		}
		break;
	case 'S':
		std::wcout << "Valitsit Sotilaan" << std::endl;

		

		if (siirtovuoro == 0) {

			AnnaLaillisetSiirrot(laillisetSiirrot);
			for (Siirto n : laillisetSiirrot)
			{
				n.TulostaRuudut();
			}
			std::wcout << std::endl;

		}
		else {
		
			AnnaLaillisetSiirrot(laillisetSiirrot);
			for (Siirto n : laillisetSiirrot)
			{
				n.TulostaRuudut();
			}
			std::wcout << std::endl;

		}
		break;
	default:
		std::wcout << "Valitsit jonkun random, en tiiä... Laita se etumerkki eteen" << std::endl;
		
		break;
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
	for (int y = 7; y >= 0; y--)
	{
		for (int x = 0; x < 8; x++)
		{
			//käydään lauta läpi ja katsotaan onko nappula siirtovuorossa olevan nappula
			if (lauta[x][y] != nullptr && lauta[x][y]->GetVari() == siirtovuoro)
			{
				
				Ruutu pos(x, y);
				std::wcout << "alkuPosX : " << x << " alkuPosY : " << y << std::endl;		
				std::wcout << "Väri:" << lauta[x][y]->GetVari() << " enum:" << lauta[x][y]->GetKoodi() << " " << lauta[x][y]->GetUnicode() << std::endl;
				Asema* asema = this;
				int tempColor = lauta[x][y]->GetVari();

				lauta[x][y]->AnnaSiirrot(lista, &pos, asema, tempColor);
			}
		}
	}
	
	//luodaan SIIRTO iteraattori listalle printtausta varten
	std::list<Siirto>::iterator it;
	//printataan lista
	std::wcout << "KAIKKI MAHDOLLISET SIIRROT: " << std::endl;
	for (it = lista.begin(); it != lista.end(); it++)
	{
		it->TulostaRuudut();
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
	//siirto iteraattori listaan
	std::list<Siirto>::iterator it;

	//käydään siirtoja läpi ja testaillaan loppuruutuja, että osuuko parametrin ruutuun.
	for (it = siirrot.begin(); it != siirrot.end(); it++)
	{
		//Selkeyttääkseni käytän target x ja target y
		int tx = it->GetLoppuRuutu().GetSarake();
		int ty = it->GetLoppuRuutu().GetRivi();

		//Siirto on sotilaan! Tarkastetaan poikkeukset
		if (it->GetNappi() == 'S') 
		{
			int x = it->GetAlkuRuutu().GetSarake();
			int y = it->GetAlkuRuutu().GetRivi();

			//sotilas on uhkaamassa ruutua viistoon.
			if (tx > x && ruutu.GetSarake() == tx && ruutu.GetRivi() == ty || 
				tx < x && ruutu.GetSarake() == tx && ruutu.GetRivi() == ty )
			{
				std::wcout << "Sotilas uhkaa ruutua! XY:" << ruutu.GetSarake() << ruutu.GetRivi() << std::endl;
				return true;
			}
			//jos sotilas vain liikkuu niin ei uhkaa ruutua, koska sotilas ei osaa syödä eteen.
			else 
			{
				//siirrytään seuraavaan iteraatioon
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
	//siirtoja ei ollu yhtään ei kai pitäs olla mahdollista
	std::wcout << "EI OLE SIIRTOJA OLLENKAAN !!, JOKU MÄTTÄÄ!" << std::endl;
	return false;
}
