#include "Ruutu.h"



Ruutu::Ruutu(int sarake, int rivi)
{
	this->sarake = sarake;
	this->rivi = rivi;
}

int Ruutu::GetRivi()
{	
	return rivi;
}

int Ruutu::GetSarake()
{
	return sarake;
}