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
	lauta[4][0] = vk;
	lauta[3][0] = vd;
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
	lauta[4][7] = mk;
	lauta[3][7] = md;
	lauta[5][7] = ml;
	lauta[6][7] = mr;
	lauta[7][7] = mt;
	
}

Ruutu Asema::EtsiKuningas(int vari)
{
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			if(lauta[x][y] != nullptr) 
			{
				if (lauta[x][y]->GetKoodi() == VK || lauta[x][y]->GetKoodi() == MK)
				{
					if (vari == lauta[x][y]->GetVari())
					{				
						return Ruutu(x, y);
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

		}
		else if (siirtovuoro == 1)
		{

			lauta[4][7] = nullptr;
			lauta[6][7] = mk;
			lauta[7][7] = nullptr;
			lauta[5][7] = mt;
	
			onkoMustaKuningasLiikkunut = true;

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

		}
		else if (siirtovuoro == 1)
		{

			lauta[4][7] = nullptr;
			lauta[2][7] = mk;
			lauta[0][7] = nullptr;
			lauta[3][7] = mt;
	
			onkoMustaKuningasLiikkunut = true;

		}	
	}
	else if (siirto->OnkoSotilaanViereenIsku()) {
		if ((	lauta[siirto->GetAlkuRuutu().GetSarake()][siirto->GetAlkuRuutu().GetRivi()]->GetKoodi() == VS ||
				lauta[siirto->GetAlkuRuutu().GetSarake()][siirto->GetAlkuRuutu().GetRivi()]->GetKoodi() == MS) && 
				(siirto->GetAlkuRuutu().GetSarake() != siirto->GetLoppuRuutu().GetSarake()) &&
				(lauta[siirto->GetLoppuRuutu().GetSarake()][siirto->GetLoppuRuutu().GetRivi()] == nullptr))
		{
			lauta[siirto->GetLoppuRuutu().GetSarake()][siirto->GetLoppuRuutu().GetRivi()] = lauta[siirto->GetAlkuRuutu().GetSarake()][siirto->GetAlkuRuutu().GetRivi()];
			lauta[siirto->GetAlkuRuutu().GetSarake()][siirto->GetAlkuRuutu().GetRivi()] = nullptr;
			lauta[siirto->GetLoppuRuutu().GetSarake()][siirto->GetAlkuRuutu().GetRivi()] = nullptr;
		}
	}
	//Tarkistetaan muut siirrot
	else
	{
		
		int alkuRiviInt = siirto->GetAlkuRuutu().GetRivi();
		int alkuSarakeInt = siirto->GetAlkuRuutu().GetSarake();

		Nappula* nappula = lauta[alkuSarakeInt][alkuRiviInt];

		int loppuRiviInt = siirto->GetLoppuRuutu().GetRivi();
		int loppuSarakeInt = siirto->GetLoppuRuutu().GetSarake();

		if (alkuRiviInt == 0 && alkuSarakeInt == 0 && loppuRiviInt == 0 && loppuSarakeInt == 0) {
			std::wcout << "ERROR NULL MOVE !" << std::endl;
			return;
		}

		if (
			(lauta[alkuSarakeInt][alkuRiviInt]->GetKoodi() == VS ||
				lauta[alkuSarakeInt][alkuRiviInt]->GetKoodi() == MS) &&
				(alkuRiviInt - loppuRiviInt == 2 || alkuRiviInt - loppuRiviInt == -2)
			)
		{
			kaksoisaskelSarakkeella = alkuSarakeInt;
		}

			lauta[alkuSarakeInt][alkuRiviInt] = nullptr;
			lauta[loppuSarakeInt][loppuRiviInt] = nappula;
		

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
		if (nappula->GetKoodi() == MT && alkuSarakeInt == 0 && alkuRiviInt == 7) {
			onkoMustaDTLiikkunut = true;
		}

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
	
	int vari = GetSiirtovuoro();
	AnnaRaakaSiirrot(lista, vari);
	AnnaLinnoitusSiirrot(lista, vari);
	KuninkaanShakit(lista, vari);

}

void Asema::AnnaRaakaSiirrot(std::list<Siirto>& lista, int vari)
{

	for (int y = 7; y >= 0; y--)
	{
		for (int x = 0; x < 8; x++)
		{
			//käydään lauta läpi ja katsotaan onko nappula siirtovuorossa olevan nappula
			if (lauta[x][y] != nullptr)
			{ 
				if (lauta[x][y]->GetVari() == vari)
				{

					lauta[x][y]->AnnaSiirrot(lista, &Ruutu(x, y), this, lauta[x][y]->GetVari());

				}
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

void Asema::AnnaLinnoitusSiirrot(std::list<Siirto>& lista, int vari)
{
	int vastustajanVuoro = this->VastustajanVuoro(vari);
	//Tarkastetaan linnoitukset ja lisätään listaan
	if (vari == 0) {
		//valkean lyhyt linna
		if (!this->GetOnkoValkeaKuningasLiikkunut() && !this->GetOnkoValkeaKTliikkunut()
			&& this->OnkoRuutuUhattu(&Ruutu(4, 0), vastustajanVuoro)
			&& this->OnkoRuutuUhattu(&Ruutu(5, 0), vastustajanVuoro) && this->OnkoRuutuUhattu(&Ruutu(6, 0), vastustajanVuoro)
			&& this->lauta[5][0] == nullptr && this->lauta[6][0] == nullptr)
		{
			//päivitetään listaan lyhytlinna
			lista.push_front(Siirto(true, false)); // lisätään listaan lyhyt linna
		}
		//valkean pitkä linna
		if (!this->GetOnkoValkeaKuningasLiikkunut() && !this->GetOnkoValkeaDTliikkunut()
			&& this->OnkoRuutuUhattu(&Ruutu(4, 0), vastustajanVuoro)
			&& this->OnkoRuutuUhattu(&Ruutu(3, 0), vastustajanVuoro) && this->OnkoRuutuUhattu(&Ruutu(3, 0), vastustajanVuoro)
			&& this->lauta[3][0] == nullptr && this->lauta[2][0] == nullptr) {
			//päivitetään listaan lyhytlinna
			lista.push_front(Siirto(false, true)); // lisätään listaan lyhyt linna
		}
	}
	if (vari == 1) {
		//mustan lyhyt linna
		if (!this->GetOnkoMustaKuningasLiikkunut() && !this->GetOnkoMustaKTliikkunut()
			&& this->OnkoRuutuUhattu(&Ruutu(4, 7), vastustajanVuoro)
			&& this->OnkoRuutuUhattu(&Ruutu(5, 7), vastustajanVuoro) && this->OnkoRuutuUhattu(&Ruutu(6, 7), vastustajanVuoro)
			&& this->lauta[5][7] == nullptr && this->lauta[6][7] == nullptr) {
			//päivitetään listaan lyhytlinna
			lista.push_front(Siirto(true, false)); // lisätään listaan lyhyt linna
		}
		//mustan pitkä linna
		if (!this->GetOnkoMustaKuningasLiikkunut() && !this->GetOnkoMustaDTliikkunut()
			&& this->OnkoRuutuUhattu(&Ruutu(4, 7), vastustajanVuoro)
			&& this->OnkoRuutuUhattu(&Ruutu(3, 7), vastustajanVuoro) && this->OnkoRuutuUhattu(&Ruutu(3, 7), vastustajanVuoro)
			&& this->lauta[3][7] == nullptr && this->lauta[2][7] == nullptr) {
			//päivitetään listaan lyhytlinna
			lista.push_front(Siirto(false, true)); // lisätään listaan lyhyt linna
		}
	}
}

void Asema::KuninkaanShakit(std::list<Siirto>& lista, int vari)
{

	//siivotutSiirrot
	std::list<Siirto> siivotutSiirrot;
	Ruutu kuninkaanSijainti = EtsiKuningas(vari);
	Asema testiAsema;
	int vastustajanVuoro = VastustajanVuoro(vari);
	
	for (Siirto s : lista)
	{
		testiAsema = *this;
		testiAsema.PaivitaAsema(&s);
		int x, y;
		
		if (s.OnkoLyhytLinna())
		{
			x = 6;

			if (this->GetSiirtovuoro() == 0) 
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
			
			if (this->GetSiirtovuoro() == 0)
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
		
			Nappula* siirtyva = this->lauta[s.GetAlkuRuutu().GetSarake()][s.GetAlkuRuutu().GetRivi()];

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

		if (testiAsema.OnkoRuutuUhattu(&Ruutu(x,y), vastustajanVuoro))
		{
			siivotutSiirrot.push_back(s);
		}
	}

	lista = siivotutSiirrot;

}

int Asema::VastustajanVuoro(int vari) 
{
	if (vari == 0) 
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

double Asema::LoppuTulos()
{
	int vari = this->GetSiirtovuoro();
	if (OnkoRuutuUhattu(&EtsiKuningas(vari), VastustajanVuoro(vari)))
		return 0; // tasapeli (patti)
	else
		return vari == 0 ? -1000.0 : 1000.0;	// matti
}

//Katsoo seuraako siirrosta mitään tosi huonoa tai onko siirto erikoinen
double Asema::SiirronKannattavuus(int vari) 
{
	return 0;
}

double Asema::LisaaVuoronPerusteella(int vari, double lisattava) 
{
	double paluu = 0;

	if (vari == 0) {
		paluu += lisattava;
	}
	else {
		paluu -= lisattava;
	}

	return paluu;
}

void Asema::JarjestaLista(std::list<Siirto>& lista) {

	double temp = 0;
	for (Siirto s : lista)
	{
		s.siirronArvo = Evaluoi();
		if (s.siirronArvo > temp) {
			lista.emplace_front(s);
		}
		temp = s.siirronArvo;
		
	}
	lista.unique();
	
}

MinMaxPaluu Asema::AlphaBeta(int syvyys, double alpha, double beta, bool maximizer)
{

	MinMaxPaluu paras;
	std::list<Siirto> siirrot;
	AnnaLaillisetSiirrot(siirrot);
	
	//Ei ole mahdollisia siirtoja, katsotaan mikä on pelin lopputulos palautetaan arvo
	if (siirrot.size() == 0)
	{
		paras.evaluointiArvo = LoppuTulos();
		return paras;
	}
	//Ollaan tutkittu puuta haluttuun syvyyteen asti, evaluoidaan seuraava siirto
	if (syvyys <= 0)
	{
		paras.evaluointiArvo = Evaluoi();
		return paras;
	}

	JarjestaLista(siirrot);
	
	//MAXIMOIJA
	if (maximizer)
	{
		paras.evaluointiArvo = -1000.0;
		for (Siirto s : siirrot)
		{
			Asema uusi = *this;
			uusi.PaivitaAsema(&s);

			MinMaxPaluu arvo = uusi.AlphaBeta(syvyys - 1, alpha, beta, false);

			//std::wcout << "MAXIMOIJAN: " << arvo.evaluointiArvo << std::endl;

			if (s.OnkoLyhytLinna() || s.OnkoPitkaLinna() || s.OnkoSotilaanViereenIsku()) {
				paras.parasSiirto = s;
				paras.evaluointiArvo = 200.0;
			}
			if (arvo.evaluointiArvo > paras.evaluointiArvo)
			{
				paras.evaluointiArvo = arvo.evaluointiArvo;
			}	
			if (paras.evaluointiArvo > alpha)
			{
				paras.parasSiirto = s;
				alpha = paras.evaluointiArvo;
				asemanArvo = paras.evaluointiArvo;
			}
			if (alpha >= beta)
			{
				//std::wcout << "pruned" << std::endl;
				break;
			}
		}
		return paras;
	}
	//MINIMOIJA
	else
	{
		paras.evaluointiArvo = 1000.0;
		for (Siirto s : siirrot)
		{
			Asema uusi = *this;
			uusi.PaivitaAsema(&s);

		
			MinMaxPaluu arvo = uusi.AlphaBeta(syvyys - 1, alpha, beta, true);
			//std::wcout << "MINIMOIJAN: " << arvo.evaluointiArvo << std::endl;

			if (s.OnkoLyhytLinna() || s.OnkoPitkaLinna() || s.OnkoSotilaanViereenIsku()) {
				paras.parasSiirto = s;
				paras.evaluointiArvo = -200.0;
			}
			if (arvo.evaluointiArvo < paras.evaluointiArvo)
			{
				paras.evaluointiArvo = arvo.evaluointiArvo;
			}
			if (paras.evaluointiArvo < beta)
			{
				paras.parasSiirto = s;
				beta = paras.evaluointiArvo;
				asemanArvo = paras.evaluointiArvo;
			}
			if (alpha >= beta)
			{
				//std::wcout << "pruned" << std::endl;
				break;
			}
		}
		return paras;
	}
}

double Asema::LaskeArvo(int vari)
{

	double valkeaArvo = 0;
	double mustaArvo = 0;
	int nappulanNimi = 0;

	//MATERIAALI
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			if (lauta[x][y] != nullptr)
			{
				
					nappulanNimi = lauta[x][y]->GetKoodi();
					//Valkoiset
					if (nappulanNimi == VD)
						valkeaArvo += kuningattarenArvo;
					if (nappulanNimi == VT)
						valkeaArvo += torninArvo;
					if (nappulanNimi == VL)
						valkeaArvo += lahetinArvo;
					if (nappulanNimi == VR)
						valkeaArvo += ratsunArvo;
					if (nappulanNimi == VS)
						valkeaArvo += sotilaanArvo;
					if (kuninkaanArvo == VK)
						valkeaArvo += kuninkaanArvo;
					//Mustat
					if (nappulanNimi == MD)
						mustaArvo += kuningattarenArvo;
					if (nappulanNimi == MT)
						mustaArvo += torninArvo;
					if (nappulanNimi == ML)
						mustaArvo += lahetinArvo;
					if (nappulanNimi == MR)
						mustaArvo += ratsunArvo;
					if (nappulanNimi == MS)
						mustaArvo += sotilaanArvo;
					if (nappulanNimi == MK)
						mustaArvo += kuninkaanArvo;
				
			}
		}
	}
	
	if (vari == 0) {
		return valkeaArvo;
	}
	else {
		return -mustaArvo;
	}
}

double Asema::LaskeAsemaArvio(int vari) 
{
	double valkeaArvo = 0;
	double mustaArvo = 0;
	int nappulanNimi = 0;

	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{

			if (lauta[x][y] != nullptr)
			{

					nappulanNimi = this->lauta[x][y]->GetKoodi();
					//Valkoiset
					if (nappulanNimi == VK)
						valkeaArvo += vKuningasTable[x][y];
					if (nappulanNimi == VD)
						valkeaArvo += vKuningatarTable[x][y];
					if (nappulanNimi == VT)
						valkeaArvo += vTorniTable[x][y];
					if (nappulanNimi == VL)
						valkeaArvo += vLahettiTable[x][y];
					if (nappulanNimi == VR)
						valkeaArvo += vRatsuTable[x][y];
					if (nappulanNimi == VS)
						valkeaArvo += vSotilasTable[x][y];
					//Mustat
					if (nappulanNimi == MK)
						mustaArvo +=  mKuningasTable[x][y];
					if (nappulanNimi == MD)
						mustaArvo +=  mKuningatarTable[x][y];
					if (nappulanNimi == MT)
						mustaArvo +=  mTorniTable[x][y];
					if (nappulanNimi == ML)
						mustaArvo += mLahettiTable[x][y];
					if (nappulanNimi == MR)
						mustaArvo += mRatsuTable[x][y];
					if (nappulanNimi == MS)
						mustaArvo += mSotilasTable[x][y];
			
			}
		}
	}

	if (vari == 0) {
		return valkeaArvo;
	}
	else {
		return -mustaArvo;
	}
}

double Asema::Evaluoi()
{

	double materiaaliKerroin = 1.0;
	double asemaKerroin = 0.1;

	double asemaArvo = (LaskeAsemaArvio(siirtovuoro) - LaskeAsemaArvio(VastustajanVuoro(siirtovuoro))) * asemaKerroin;
	
	double materiaaliArvo = (LaskeArvo(siirtovuoro) - LaskeArvo(VastustajanVuoro(siirtovuoro))) * materiaaliKerroin;
	
	return materiaaliArvo + asemaArvo;
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
			if (this->lauta[i][j] != nullptr) 
			{
				if (this->lauta[i][j]->GetVari() == vastustajanVari)
					this->lauta[i][j]->AnnaSiirrot(vastustajaSiirrotLista, &Ruutu(i, j), this, vastustajanVari); // myöh.sidonta
			}
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
