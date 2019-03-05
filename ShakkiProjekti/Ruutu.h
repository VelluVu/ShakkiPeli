#pragma once
class Ruutu
{
private:
	int sarake;
	int rivi;

public:
	Ruutu(int sarake, int rivi);
	Ruutu() {};
	int GetRivi();
	int GetSarake();
	bool operator==(const Ruutu& ruutu) const
	{
		if (sarake == ruutu.sarake && rivi == ruutu.rivi) 
		{
			return true;
		}
		return false;
	}
};

