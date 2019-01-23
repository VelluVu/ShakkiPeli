#include "Ruutu.h"



Ruutu::Ruutu(int rivi, int sarake)
{
	this->rivi = rivi;
	this->sarake = sarake;
}

Ruutu::Ruutu()
{
}

int Ruutu::GetRivi()
{
	return rivi;
}

int Ruutu::GetSarake()
{
	return sarake;
}


Ruutu::~Ruutu()
{
}
