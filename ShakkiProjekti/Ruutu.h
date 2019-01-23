#pragma once
class Ruutu
{
private:
	int sarake;
	int rivi;

public:
	Ruutu(int rivi, int sarake);
	Ruutu();
	int GetRivi();
	int GetSarake();
	~Ruutu();
};

