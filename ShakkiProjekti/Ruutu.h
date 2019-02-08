#pragma once
class Ruutu
{
private:
	int sarake;
	int rivi;

public:
	Ruutu(int sarake, int rivi);
	Ruutu();
	int GetRivi();
	int GetSarake();
	~Ruutu();
};

