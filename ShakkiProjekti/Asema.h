#pragma once

#include <list>
#include <string>
#include "Siirto.h"
#include "MinMaxPaluu.h"
#include "Nappula.h"
#include "Sotilas.h"
#include "Torni.h"
#include "Ratsu.h"
#include "Lahetti.h"
#include "Kuningas.h"
#include "Kunigatar.h"

class Asema
{
private:

	int siirtovuoro;
	bool onkoValkeaKuningasLiikkunut;
	bool onkoMustaKuningasLiikkunut;
	bool onkoValkeaDTLiikkunut;
	bool onkoValkeaKTLiikkunut;
	bool onkoMustaDTLiikkunut;
	bool onkoMustaKTLiikkunut;

public:
	
	//Konstruktori luo alkuaseman laudalle
	Asema();

	//Lauta [rivi] [sarake]
	Nappula* lauta[8][8];

	static Nappula* vs;
	static Nappula* vt;
	static Nappula* vr;
	static Nappula* vl;
	static Nappula* vk;
	static Nappula* vd;

	static Nappula* ms;
	static Nappula* mt;
	static Nappula* mr;
	static Nappula* ml;
	static Nappula* mk;
	static Nappula* md;
	
	Ruutu EtsiKuningas(int vari);
	void PaivitaAsema(Siirto* siirto);
	int GetSiirtovuoro();
	void SetSiirtovuoro(int vari);
	void AnnaLaillisetSiirrot(std::list<Siirto>& lista);
	void AnnaRaakaSiirrot(std::list<Siirto>& lista, int vari);
	void TestaaLiiike(Siirto* s);
	void AnnaLinnoitusSiirrot(std::list<Siirto>& lista);
	void KuninkaanShakit(std::list<Siirto>& lista);
	double LoppuTulos();
	MinMaxPaluu MiniMax(int syvyys, double alpha, double beta);
	double Evaluoi();
	bool GetOnkoValkeaKuningasLiikkunut();
	bool GetOnkoMustaKuningasLiikkunut();
	bool GetOnkoValkeaDTliikkunut();
	bool GetOnkoValkeaKTliikkunut();
	bool GetOnkoMustaDTliikkunut();
	bool GetOnkoMustaKTliikkunut();
	bool OnkoRuutuUhattu(Ruutu* ruutu, std::list<Siirto>& siirrot);

	// Ohestalyöntiä varten (-1 = sotilaan kaksoisaskelta ei tapahtunut edellisellä siirrolla).
	int kaksoisaskelSarakkeella = -1;
	double sotilaanArvo = 1.0; // valkoisen, mustalla neg katso siirtovuoron perusteella
	double ratsunArvo = 3.0;
	double lahetinArvo = 3.25;
	double torninArvo = 5;
	double kuningattarenArvo = 9;

};

