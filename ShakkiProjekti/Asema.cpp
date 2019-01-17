#include "Asema.h"



Asema::Asema()
{
	//nollaa ylimääräinen 'tauhka'
	for (size_t x = 0; x < 8; x++)
	{
		for (size_t y = 0; y < 8; y++)
		{
			lauta[x][y] = 0;
		}
	}

	//alusta valkoiset nappulat
	for (size_t i = 0; i < 8; i++)
	{
		vs[i] = new Nappula(L"\u2659", 0, VS);
	}
	for (size_t i = 0; i < 2; i++)
	{
		vt[i] = new Nappula(L"\u2656", 0, VT);
	}
	for (size_t i = 0; i < 2; i++)
	{
		vr[i] = new Nappula(L"\u2658", 0, VR);
	}
	for (size_t i = 0; i < 2; i++)
	{
		vl[i] = new Nappula(L"\u2657", 0, VL);
	}
	vk = new Nappula(L"\u2654", 0 ,VK);
	vd = new Nappula(L"\u2655", 0 ,VD);

	//Aseta ne Asemaan
	for (size_t i = 0; i < 8; i++)
	{
		lauta[1][i] = vs[i];
	}
	
	lauta[0][0] = vt[0];
	lauta[1][0] = vr[0];
	lauta[2][0] = vl[0];
	lauta[3][0] = vk;
	lauta[4][0] = vd;
	lauta[5][0] = vl[1];
	lauta[6][0] = vr[1];
	lauta[7][0] = vt[1];

	//alusta mustat nappulat
	for (size_t i = 0; i < 8; i++)
	{
		ms[i] = new Nappula(L"\u265F", 1, MS);
	}
	for (size_t i = 0; i < 2; i++)
	{
		mt[i] = new Nappula(L"\u265C", 1, MT);
	}
	for (size_t i = 0; i < 2; i++)
	{
		mr[i] = new Nappula(L"\u265E", 1, MR);
	}
	for (size_t i = 0; i < 2; i++)
	{
		ml[i] = new Nappula(L"\u265D", 1, ML);
	}
	mk = new Nappula(L"\u265A", 1, MK);
	md = new Nappula(L"\u265B", 1, MD);

	//Aseta ne Asemaan
	for (size_t i = 0; i < 8; i++)
	{
		lauta[i][6] = ms[i];
	}
	lauta[0][7] = mt[0];
	lauta[1][7] = mr[0];
	lauta[2][7] = ml[0];
	lauta[4][7] = mk;
	lauta[3][7] = md;
	lauta[5][7] = ml[1];
	lauta[6][7] = mr[1];
	lauta[7][7] = mt[1];

}


Asema::~Asema()
{
	//Tyhjää kaikki muistipaikat
	delete mk, md, vk, vd;
	mk, md, vk, vd = 0;
	for (size_t i = 0; i < 2; i++)
	{
		delete vt[i], vr[i], vl[i], mt[i], mr[i], ml[i];
		vt[i], vr[i], vl[i], mt[i], mr[i], ml[i] = 0;
	}
	for (size_t i = 0; i < 8; i++)
	{
		delete vs[i], ms[i];
		vs[i], ms[i] = 0;
	}
	for (size_t x = 0; x < 8; x++)
	{
		for (size_t y = 0; y < 8; y++)
		{
			delete lauta[x][y];
			lauta[x][y] = 0;
		}
	}
	
}
