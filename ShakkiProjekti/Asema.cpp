#include "Asema.h"
#include<algorithm>

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
	
	//kaksoisaskel flagi
	this->kaksoisaskelSarakkeella = -1;

	//Onko siirto lyhytlinna
	if (siirto->OnkoLyhytLinna())
	{	
		if (siirtovuoro == 0) {

			lauta[4][0] = nullptr;
			lauta[6][0] = vk;
			lauta[7][0] = nullptr;
			lauta[5][0] = vt;

			onkoValkeaKuningasLiikkunut = true;
			onkoValkeaKTLiikkunut = true;

		}
		else if (siirtovuoro == 1)
		{

			lauta[4][7] = nullptr;
			lauta[6][7] = mk;
			lauta[7][7] = nullptr;
			lauta[5][7] = mt;

			onkoMustaKuningasLiikkunut = true;
			onkoMustaKTLiikkunut = true;

		}
	}
	else if (siirto->OnkoPitkaLinna()) //onko siirto pitkälinna
	{	
		if (siirtovuoro == 0)
		{

			lauta[4][0] = nullptr;
			lauta[2][0] = vk;
			lauta[0][0] = nullptr;
			lauta[3][0] = vt;

			onkoValkeaKuningasLiikkunut = true;
			onkoValkeaKTLiikkunut = true;

		}
		else if (siirtovuoro == 1)
		{

			lauta[4][7] = nullptr;
			lauta[2][7] = mk;
			lauta[0][7] = nullptr;
			lauta[3][7] = mt;

			onkoMustaKuningasLiikkunut = true;
			onkoMustaKTLiikkunut = true;

		}
	}
	else //Tarkistetaan muut siirrot
	{

		//Ottaa siirron alkuruudussa olleen nappulan talteen 
		int alkuRiviInt = siirto->GetAlkuRuutu().GetRivi();
		int alkuSarakeInt = siirto->GetAlkuRuutu().GetSarake();
		Nappula* nappula = lauta[alkuSarakeInt][alkuRiviInt];

		//Laittaa talteen otetun nappulan uuteen ruutuun
		int loppuRiviInt = siirto->GetLoppuRuutu().GetRivi();
		int loppuSarakeInt = siirto->GetLoppuRuutu().GetSarake();

		if ((lauta[alkuSarakeInt][alkuRiviInt]->GetKoodi() == VS || 
			lauta[alkuSarakeInt][alkuRiviInt]->GetKoodi() == MS) &&
			(alkuRiviInt - loppuRiviInt == 2 || alkuRiviInt - loppuRiviInt == -2))
		{

			kaksoisaskelSarakkeella = alkuSarakeInt;
		}

		// Ohestalyönti on tyhjään ruutuun. Vieressä oleva (sotilas) poistetaan.
		if ((lauta[alkuSarakeInt][alkuRiviInt]->GetKoodi() == VS ||
			lauta[alkuSarakeInt][alkuRiviInt]->GetKoodi() == MS) &&
			(alkuSarakeInt != loppuSarakeInt) &&
			(lauta[loppuSarakeInt][loppuRiviInt] == nullptr))
		{
			lauta[loppuSarakeInt][alkuRiviInt] = nullptr;
		}
		else
		{
			lauta[alkuSarakeInt][alkuRiviInt] = nullptr;
			lauta[loppuSarakeInt][loppuRiviInt] = nappula;
		}

		if (siirto->miksiKorotetaan != nullptr)
		{
			lauta[loppuSarakeInt][loppuRiviInt] = siirto->miksiKorotetaan;
		}
		// katsotaan jos liikkunut nappula on kuningas niin muutetaan onkoKuningasLiikkunut arvo (molemmille väreille)
		if (nappula->GetKoodi() == VK) {
			onkoValkeaKuningasLiikkunut = true;
		}
		if (nappula->GetKoodi() == MK) {
			onkoMustaKuningasLiikkunut = true;
		}
		// katsotaan jos liikkunut nappula on torni niin muutetaan onkoTorniLiikkunut arvo (molemmille väreille ja molemmille torneille)
		if (nappula->GetKoodi() == VT && alkuSarakeInt == 7 && alkuRiviInt == 0) {
			onkoValkeaKTLiikkunut = true;
		}
		if (nappula->GetKoodi() == VT && alkuSarakeInt == 0 && alkuRiviInt == 0) {
			onkoValkeaDTLiikkunut = true;
		}
		if (nappula->GetKoodi() == MT && alkuSarakeInt == 7 && alkuRiviInt == 7) {
			onkoMustaKTLiikkunut = true;
		}
		if (nappula->GetKoodi() == VT && alkuSarakeInt == 0 && alkuRiviInt == 7) {
			onkoMustaDTLiikkunut = true;
		}
	
		//poistin ylimääräisen wchar koko ohjelmasta, ja tästä johtuen muutin montaa luokkaa ettei käytä sitä
		////Testaa minkä napin siirto on kyseessä, siirrettävän napin etumerkin perusteella
		//switch (siirto->GetNappi())
		//{
		//case 'K':
		//	//std::wcout << "Valitsit Kuninkaan" << std::endl;

		//	lauta[tx][ty] = lauta[x][y];
		//	lauta[x][y] = nullptr;

		//	if (siirtovuoro == 0 && !GetOnkoValkeaKTliikkunut())
		//	{

		//		onkoValkeaKuningasLiikkunut = true;

		//	}
		//	else if (siirtovuoro == 1 && !GetOnkoMustaKuningasLiikkunut())
		//	{

		//		onkoMustaKuningasLiikkunut = true;

		//	}

		//	break;

		//case 'D':
		//	//std::wcout << "Valitsit Daamin" << std::endl;

		//	lauta[tx][ty] = lauta[x][y];
		//	lauta[x][y] = nullptr;

		//	if (siirtovuoro == 0 && !GetOnkoValkeaDTliikkunut())
		//	{

		//		onkoValkeaDTLiikkunut = true;

		//	}
		//	else if (siirtovuoro == 1 && !GetOnkoMustaDTliikkunut())
		//	{

		//		onkoMustaDTLiikkunut = true;
		//	}

		//	break;

		//case 'L':
		//	//std::wcout << "Valitsit Lähetin" << std::endl;

		//	lauta[tx][ty] = lauta[x][y];
		//	lauta[x][y] = nullptr;

		//	break;

		//case 'R':
		//	//std::wcout << "Valitsit Ratsun" << std::endl;

		//	lauta[tx][ty] = lauta[x][y];
		//	lauta[x][y] = nullptr;

		//	break;

		//case 'T':
		//	//std::wcout << "Valitsit Tornin" << std::endl;

		//	lauta[tx][ty] = lauta[x][y];
		//	lauta[x][y] = nullptr;

		//	if (siirtovuoro == 0 && !GetOnkoValkeaKTliikkunut())
		//	{
		//		onkoValkeaKTLiikkunut = true;
		//	}
		//	else if (siirtovuoro == 1 && !GetOnkoMustaKTliikkunut())
		//	{
		//		onkoMustaKTLiikkunut = true;
		//	}

		//	break;

		//case 'S':
		//	//std::wcout << "Valitsit Sotilaan" << std::endl;
		//	if (siirto->miksiKorotetaan != nullptr)
		//	{
		//		lauta[tx][ty] = siirto->miksiKorotetaan;
		//		lauta[x][y] = nullptr;
		//		break;
		//	}
		//	// Tarkistetaan oliko sotilaan kaksoisaskel
		//	// (asetetaan kaksoisaskel-lippu)
		//	if
		//		((lauta[x][y]->GetKoodi() == VS || lauta[x][y]->GetKoodi() == MS) &&
		//		(y - ty == 2 || y - ty == -2))
		//	{
		//		kaksoisaskelSarakkeella = x;
		//	}
		//	if (lauta[x][y] != nullptr && lauta[x][y]->GetKoodi() == VS &&
		//		lauta[tx][ty] == nullptr && x != tx ||
		//		lauta[x][y] != nullptr && lauta[x][y]->GetKoodi() == MS &&
		//		lauta[tx][ty] == nullptr && x != tx)
		//	{
		//		lauta[tx][y] = nullptr;
		//		break;
		//	}
		//	if (lauta[x][y] != nullptr && lauta[x][y]->GetKoodi() == VS ||
		//		lauta[x][y] != nullptr && lauta[x][y]->GetKoodi() == MS)
		//	{
		//		//lauta[x][y]->SetOnkoLiikkunut(true);
		//	}
		//	lauta[tx][ty] = lauta[x][y];
		//	lauta[x][y] = nullptr;

		//	break;

		//default:
		//	std::wcout << "Sotilas" << std::endl;

		//	break;
		//}
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

				lauta[x][y]->AnnaSiirrot(lista, &Ruutu(x, y), this, lauta[x][y]->GetVari());

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
	int vastustajanVuoro = VastustajanVuoro();
	//Tarkastetaan linnoitukset ja lisätään listaan
	if (siirtovuoro == 0) {
		//valkean lyhyt linna
		if (!GetOnkoValkeaKuningasLiikkunut() && !GetOnkoValkeaKTliikkunut()
			&& OnkoRuutuUhattu(&Ruutu(4, 0), vastustajanVuoro)
			&& OnkoRuutuUhattu(&Ruutu(5, 0), vastustajanVuoro) && OnkoRuutuUhattu(&Ruutu(6, 0), vastustajanVuoro)
			&& lauta[5][0] == nullptr && lauta[6][0] == nullptr)
		{
			//päivitetään listaan lyhytlinna
			lista.push_back(Siirto(true, false)); // lisätään listaan lyhyt linna
		}
		//valkean pitkä linna
		if (!GetOnkoValkeaKuningasLiikkunut() && !GetOnkoValkeaDTliikkunut()
			&& OnkoRuutuUhattu(&Ruutu(4, 0), vastustajanVuoro)
			&& OnkoRuutuUhattu(&Ruutu(3, 0), vastustajanVuoro) && OnkoRuutuUhattu(&Ruutu(3, 0), vastustajanVuoro)
			&& lauta[3][0] == nullptr && lauta[2][0] == nullptr) {
			//päivitetään listaan lyhytlinna
			lista.push_back(Siirto(false, true)); // lisätään listaan lyhyt linna
		}
	}
	if (siirtovuoro == 1) {
		//mustan lyhyt linna
		if (!GetOnkoMustaKuningasLiikkunut() && !GetOnkoMustaKTliikkunut()
			&& OnkoRuutuUhattu(&Ruutu(4, 7), vastustajanVuoro)
			&& OnkoRuutuUhattu(&Ruutu(5, 7), vastustajanVuoro) && OnkoRuutuUhattu(&Ruutu(6, 7), vastustajanVuoro)
			&& lauta[5][7] == nullptr && lauta[6][7] == nullptr) {
			//päivitetään listaan lyhytlinna
			lista.push_back(Siirto(true, false)); // lisätään listaan lyhyt linna
		}
		//mustan pitkä linna
		if (!GetOnkoMustaKuningasLiikkunut() && !GetOnkoMustaDTliikkunut()
			&& OnkoRuutuUhattu(&Ruutu(4, 7), vastustajanVuoro)
			&& OnkoRuutuUhattu(&Ruutu(3, 7), vastustajanVuoro) && OnkoRuutuUhattu(&Ruutu(3, 7), vastustajanVuoro)
			&& lauta[3][7] == nullptr && lauta[2][7] == nullptr) {
			//päivitetään listaan lyhytlinna
			lista.push_back(Siirto(false, true)); // lisätään listaan lyhyt linna
		}
	}
}

void Asema::KuninkaanShakit(std::list<Siirto>& lista)
{

	//lista vastustajanSiirroille
	std::list<Siirto> vastustajanSiirrot;
	//siivotutSiirrot
	std::list<Siirto> siivotutSiirrot;
	Ruutu kuninkaanSijainti = EtsiKuningas(KummanVuoro());
	Asema testiAsema;
	
	for (Siirto s : lista)
	{
		testiAsema = *this;
		testiAsema.PaivitaAsema(&s);
		int x, y;

		if (s.OnkoLyhytLinna())
		{
			x = 6;

			if (KummanVuoro() == 0) 
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
			
			if (KummanVuoro() == 0) 
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

		if (testiAsema.OnkoRuutuUhattu(&Ruutu(x,y), VastustajanVuoro()))
		{
			siivotutSiirrot.push_back(s);
		}
	}

	lista = siivotutSiirrot;

}

int Asema::KummanVuoro() 
{
	if (siirtovuoro == 0) 
	{
		return 0;
	}
	else if (siirtovuoro == 1)
	{
		return 1;
	}
}

int Asema::VastustajanVuoro() 
{
	if (siirtovuoro == 0) 
	{
		return 1;
	}
	else if (siirtovuoro == 1) 
	{
		return 0;
	}
}

double Asema::LoppuTulos()
{
	
	if (OnkoRuutuUhattu(&EtsiKuningas(KummanVuoro()), VastustajanVuoro()))
		return 0; // tasapeli (patti)
	else
		return siirtovuoro == 0 ? -1000000 : 1000000;	// matti
}

MinMaxPaluu Asema::MiniMax(int syvyys, double alpha, double beta, bool maximoija)
{

	MinMaxPaluu paras;
	if (maximoija)
		paras.evaluointiArvo = -1000000.0;
	else
		paras.evaluointiArvo = 1000000.0;

	std::list<Siirto> siirrot;
	AnnaLaillisetSiirrot(siirrot);

	//Ei ole mahdollisia siirtoja, katsotaan mikä on pelin lopputulos palautetaan arvo
	if (siirrot.size() == 0)
	{
		paras.evaluointiArvo = LoppuTulos();
		return paras;
	}
	//Ollaan tutkittu puuta haluttuun syvyyteen asti, evaluoidaan seuraava järkevä siirto laskemalla
	if (syvyys == 0)
	{
		paras.evaluointiArvo = Evaluoi();
		return paras;
	}


		//Tutkii jokaista siirtoa seuraavassa asemassa
	for (Siirto s : siirrot)
	{

		Asema uusi = *this;
		uusi.PaivitaAsema(&s);

		if (maximoija)
		{
			
			//Rekursio
			MinMaxPaluu arvo = uusi.MiniMax(syvyys - 1, alpha, beta, true);
			//std::wcout << arvo.evaluointiArvo << std::endl;
			//Katsoo onko siirron arvo suurempi / pienempi vuorosta riippuen alku arvoon verrattuna
			if (arvo.evaluointiArvo > paras.evaluointiArvo)
			{
				paras.evaluointiArvo = arvo.evaluointiArvo;
				paras.parasSiirto = s;

			}
			if (arvo.evaluointiArvo > alpha)
			{
				alpha = arvo.evaluointiArvo;
			
			}
			if (alpha >= beta)
			{
				std::wcout << "CUTOUT: " << std::endl;
				s.TulostaRuudut();
				break;
			}
		}
		else
		{
			
			//Rekursio
			MinMaxPaluu arvo = uusi.MiniMax(syvyys - 1, alpha, beta, false);
			//std::wcout << arvo.evaluointiArvo << std::endl;
			//Katsoo onko siirron arvo suurempi / pienempi vuorosta riippuen alku arvoon verrattuna
			if (arvo.evaluointiArvo < paras.evaluointiArvo)
			{

				paras.evaluointiArvo = arvo.evaluointiArvo;
				paras.parasSiirto = s;

			}

			if (arvo.evaluointiArvo < beta)
			{

				beta = arvo.evaluointiArvo;
		
			}
			
			if (alpha >= beta)
			{
				std::wcout << "CUTOUT: " << std::endl;
				s.TulostaRuudut();
				std::wcout << "BETA: " << alpha << std::endl;
				break;
			}
		}
	}		
	return paras;
}

double Asema::LaskeArvo(int vari)
{

	double valkeaArvo = 0;
	double mustaArvo = 0;

	//MATERIAALI
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			if (lauta[x][y] != nullptr)
			{
				int nappulanNimi = this->lauta[x][y]->GetKoodi();
				//Valkoiset
				if (nappulanNimi == VD)
					valkeaArvo += 90;
				if (nappulanNimi == VT)
					valkeaArvo += 15;
				if (nappulanNimi == VL)
					valkeaArvo += 12;
				if (nappulanNimi == VR)
					valkeaArvo += 8;
				if (nappulanNimi == VS)
					if (lauta[3][1] || lauta[4][1])
						valkeaArvo += 5;
					else
						valkeaArvo += 2.5;
				//Mustat
				if (nappulanNimi == MD)
					mustaArvo += 90;
				if (nappulanNimi == MT)
					mustaArvo += 15;
				if (nappulanNimi == ML)
					mustaArvo += 12;
				if (nappulanNimi == MR)
					mustaArvo += 8;
				if (nappulanNimi == MS)
					if (lauta[3][6] || lauta[4][6])
						mustaArvo += 5;
					else
						mustaArvo += 2.5;
			}
		}
	}
	if (vari == 0) {
		return valkeaArvo;
	}
	else {
		return mustaArvo;
	}
}

double Asema::Evaluoi()
{

	double materiaaliKerroin = 1.0;
	
	double materiaaliArvo = LaskeArvo(0) - LaskeArvo(1);
	
	return materiaaliArvo * materiaaliKerroin;
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

bool Asema::OnkoRuutuUhattu(Ruutu* ruutu, int vastustajanVari)
{
	
	std::list<Siirto> vastustajaSiirrotLista;
	//Väreittäin käydään läpi kaikki ruudut ja niissä olevan nappulan siirrot kerätään vastustajan siirtolistaan
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (this->lauta[i][j] == NULL) {
				continue;
			}
			if (this->lauta[i][j]->GetVari() == vastustajanVari)
				this->lauta[i][j]->AnnaSiirrot(vastustajaSiirrotLista, &Ruutu(i, j), this, vastustajanVari); // myöh.sidonta
		}
	}
	// Käydään vastustajaSiirtoLista läpi ja jos sieltä löytyy tarkasteltava ruutu niin tiedetään sen olevan uhattu
	bool ruutuOk = true;
	for (auto s : vastustajaSiirrotLista)
	{
		if (ruutu->GetSarake() == s.GetLoppuRuutu().GetSarake() && ruutu->GetRivi() == s.GetLoppuRuutu().GetRivi()) {
			ruutuOk = false;
			break;
		}
	}
	return ruutuOk;

	////käydään siirtoja läpi ja testaillaan loppuruutuja, että osuuko parametrin ruutuun.
	//for (Siirto s : siirrot)
	//{
	//	//Selkeyttääkseni käytän target x ja target y
	//	int tx = s.GetLoppuRuutu().GetSarake();
	//	int ty = s.GetLoppuRuutu().GetRivi();

	//	//Siirto on sotilaan! Tarkastetaan poikkeukset
	//	if () 
	//	{
	//		int x = s.GetAlkuRuutu().GetSarake();
	//		int y = s.GetAlkuRuutu().GetRivi();

	//		//sotilas on uhkaamassa ruutua viistoon.
	//		//virhe..
	//		if (tx == x + 1 && ruutu->GetSarake() == tx && ruutu->GetRivi() == ty && siirtovuoro == 1 ||
	//			tx == x - 1 && ruutu->GetSarake() == tx && ruutu->GetRivi() == ty && siirtovuoro == 0)
	//		{
	//			//std::wcout << "Sotilas uhkaa ruutua! XY:" << ruutu->GetSarake() << ruutu->GetRivi() << std::endl;
	//			return true;
	//		}
	//		//jos sotilas vain liikkuu niin ei uhkaa ruutua, koska sotilas ei osaa syödä eteen.
	//		else 
	//		{
	//			continue;
	//		}
	//	}
	//	//Siirto ei ole sotilaan
	//	else 
	//	{
	//		//Uhkaa ruutua
	//		if (tx == ruutu->GetSarake() && ty == ruutu->GetRivi())
	//		{
	//			//std::wcout << "Joku uhkaa ruutua! XY:" << ruutu->GetSarake() << ruutu->GetRivi() << std::endl;
	//			return true;
	//		}

	//	}
	//}

	//return false;

}
