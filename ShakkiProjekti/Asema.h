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
#include "Kuningatar.h"

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
	int VastustajanVuoro(int vari);
	double LoppuTulos();
	double SiirronKannattavuus(int vari);
	MinMaxPaluu AlphaBeta(int syvyys, double alpha, double beta, bool maximizer);
	double LaskeArvo(int vari);
	double LaskeAsemaArvio(int vari);
	double Evaluoi();
	bool GetOnkoValkeaKuningasLiikkunut();
	bool GetOnkoMustaKuningasLiikkunut();
	bool GetOnkoValkeaDTliikkunut();
	bool GetOnkoValkeaKTliikkunut();
	bool GetOnkoMustaDTliikkunut();
	bool GetOnkoMustaKTliikkunut();
	bool OnkoRuutuUhattu(Ruutu* ruutu, int vastustajanVari);

	// Ohestalyöntiä varten (-1 = sotilaan kaksoisaskelta ei tapahtunut edellisellä siirrolla).
	int kaksoisaskelSarakkeella = -1;
	double sotilaanArvo = 1.0; // valkoisen, mustalla neg katso siirtovuoron perusteella
	double ratsunArvo = 3.0;
	double lahetinArvo = 3.25;
	double torninArvo = 5.0;
	double kuningattarenArvo = 9.0;
	double kuninkaanArvo = 18.0;
	
	double asemanArvo;

	//SijaintiPOjot kaikille
	double vSotilasTable[8][8] = { 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0,
												 5.0 , 5.0 , 5.0 , 5.0 , 5.0	, 5.0 , 5.0 , 5.0 ,
												 1.0 , 1.0 , 2.0 , 3.0 , 3.0 , 2.0 , 1.0 , 1.0 ,
												 0.5 , 0.5 , 1.0 , 2.5 , 2.5 , 1.0 , 0.5 , 0.5 ,
												 0.0 , 0.0 , 0.0 , 2.0 , 2.0 , 0.0 , 0.0 , 0.0 ,
												 0.5 , -0.5 , -1.0 , 0.0 , 0.0 , -1.0 , -0.5 , 0.5 ,
												 0.5 , 1.0 , 1.0 , -2.0 , -2.0 , 1.0 , 1.0 , 0.5 ,
												 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
	};
	double vTorniTable[8][8] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
												0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5 ,
												-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5 ,
												-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5 ,
												-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5 ,
												-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5 ,
												-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5 ,
												0.0, 0.0, 0.0, 0.5, 0.5, 0.0, 0.0, 0.0
	};
	double vRatsuTable[8][8] = {	-5.0, -4.0, -3.0, -3.0, -3.0, -3.0, -4.0, -5.0,
													-4.0, -2.0, 0.0, 0.0, 0.0, 0.0, -2.0, -4.0 ,
													-3.0, 0.0, 1.0, 1.5, 1.5, 1.0, 0.0, -3.0 ,
													-3.0, 0.5, 1.5, 2.0, 2.0, 1.5, 0.5, -3.0 ,
													-3.0, 0.0, 1.5, 2.0, 2.0, 1.5, 0, -3.0 ,
													-3.0, 0.5, 1.0, 1.5, 1.5, 1.0, 0.5, -3.0 ,
													-4.0, -2.0, 0.0, 0.5, 0.5, 0.0, -2.0, -4.0 ,
													-5.0, -4.0, -3.0, -3.0, -3.0, -3.0, -4.0, -5.0
	};
	double vLahettiTable[8][8] = {-2.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -2.0,
													-1.0,	 0.0,   0.0,  0.0,   0.0,  0.0,  0.0, -1.0 ,
													-1.0,  0.0,   0.5,  1.0,   1.0,  0.5,  0.0, -1.0 ,
													-1.0,  0.5,   0.5,  1.0,   1.0,  0.5,  0.5, -1.0 ,
													-1.0,  0.0,   1.0,  1.0,   1.0,  1.0,  0.0, -1.0 ,
													-1.0,  1.0,   1.0,  1.0,   1.0,  1.0,  1.0, -1.0 ,
													-1.0,  0.5,   0.0,  0.0,   0.0,  0.0,  0.5, -1.0 ,
													-2.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -2.0
	};
	double vKuningasTable[8][8] = {	-3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0,
														-3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0 ,
														-3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0 ,
														-3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0 ,
														-2.0, -3.0, -3.0, -4.0, -4.0, -3.0, -3.0, -2.0 ,
														-1.0, -2.0, -2.0, -2.0, -2.0, -2.0, -2.0, -1.0 ,
														 2.0,	 2.0,	 0.0,	 0.0,	 0.0,	 0.0,	 2.0,	 2.0 ,
														 2.0,	 3.0,	 1.0,	 0.0,	 0.0,	 1.0,	 3.0,	 2.0
	};
	double vKuningatarTable[8][8]={ -2.0, -1.0, -1.0, -0.5, -0.5, -1.0, -1.0, -2.0,
														 -1.0,	   0.0,  0.0,  0.0,   0.0,  0.0,   0.0, -1.0 ,
														 -1.0,   0.0,  0.5,  0.5,   0.5,  0.5,   0.0, -1.0 ,
														 -0.5,   0.0,  0.5,  0.5,   0.5,  0.5,   0.0, -0.5 ,
														  0.0,   0.0,   0.5,  0.5,  0.5,  0.5,   0.0, -0.5 ,
														 -1.0,   0.0,   0.5,  0.5,  0.5,  0.5,   0.0, -1.0 ,
														 -1.0,   0.0,   0.5,  0.0,  0.0,  0.0,   0.0, -1.0 ,
														 -2.0,  -1.0, -1.0, -0.5, -0.5, -1.0, -1.0, -2.0
	};
	double mSotilasTable[8][8] = { 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0,
												 0.5 , 1.0 , 1.0 , -2.0 , -2.0	, 1.0 , 1.0 , 0.5 ,
												 0.5 , -0.5 , -1.0 , 0.0 , 0.0 , -1.0 , -0.5 , 0.5 ,
												 0.0 , 0.0 , 0.0 , 2.0 , 2.0 , 0.0 , 0.0 , 0.0 ,
												 0.5 , 0.5 , 1.0 , 2.5 , 2.5 , 1.0 , 0.5 , 0.5 ,
												 1.0 , 1.0 , 2.0 , 3.0 , 3.0 , 2.0 , 1.0 , 1.0 ,
												 5.0 , 5.0 , 5.0 , 5.0 , 5.0 , 5.0 , 5.0 , 5.0 ,
												 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
	};
	double mTorniTable[8][8] = { 0.0, 0.0, 0.0, 0.5, 0.5, 0.0, 0.0, 0.0,
												 -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5 ,
												-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5 ,
												-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5 ,
												-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5 ,
												-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5 ,
												0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,  0.5 ,
												0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
	};
	double mRatsuTable[8][8] = { -5.0, -4.0, -3.0, -3.0, -3.0, -3.0, -4.0, -5.0,
													-4.0, -2.0, 0.0, 0.5, 0.5, 0.0, -2.0, -4.0 ,
													-3.0, 0.5, 1.0, 1.5, 1.5, 1.0, 0.5, -3.0 ,
													-3.0, 0.0, 1.5, 2.0, 2.0, 1.5, 0.0, -3.0 ,
													-3.0, 0.5, 1.5, 2.0, 2.0, 1.5, 0.5, -3.0 ,
													-3.0, 0.0, 1.0, 1.5, 1.5, 1.0, 0.0, -3.0 ,
													-4.0, -2.0, 0.0, 0.0, 0.0, 0.0, -2.0, -4.0 ,
													-5.0, -4.0, -3.0, -3.0, -3.0, -3.0, -4.0, -5.0
	};
	double mLahettiTable[8][8] = { -2.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -2.0,
													-1.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.5, -1.0 ,
													-1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0 ,
													-1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, -1.0 ,
													-1.0, 0.5, 0.5, 1.0, 1.0, 0.5, 0.5, -1.0 ,
													-1.0, 0.0, 0.5, 1.0, 1.0, 0.5, 0.0, -1.0 ,
													-1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0 ,
													-2.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -2.0
	};
	double mKuningasTable[8][8] = { 2.0, 3.0, 1.0, 0.0, 0.0, 1.0, 3.0, 2.0,
														2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 2.0, 2.0 ,
														-1.0, -2.0, -2.0, -2.0, -2.0, -2.0, -2.0, -1.0 ,
														-2.0, -3.0, -3.0, -4.0, -4.0, -3.0, -3.0, -2.0 ,
														-3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0 ,
														-3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0 ,
														-3.0, -4.0 , -4.0, -5.0, -5.0, -4.0 , 4.0, -3.0 ,
														 -3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0
	};
	double mKuningatarTable[8][8] = { -2.0, -1.0, -1.0, -0.5, -0.5, -1.0, -1.0, -2.0,
														-1.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, -1.0 ,
														-1.0, 0.0, 0.5, 0.5, 0.5, 0.5, 0.0, -1.0 ,
														-0.5, 0.0, 0.5, 0.5, 0.5, 0.5, 0.0, 0.0 ,
														 -0.5, 0.0, 0.5, 0.5, 0.5, 0.5, 0.0, 0.5 ,
														-1.0, 0.0, 0.5, 0.5, 0.5, 0.5, 0.0, -1.0 ,
														-1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0 ,
														-2.0, -1.0, -1.0, -0.5, -0.5, -1.0, -1.0, -2.0
	};


};

