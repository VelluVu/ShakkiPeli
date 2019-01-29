#include "Torni.h"

void Torni::AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari)
{
	Ruutu _pos(pos->GetRivi(), pos->GetSarake());
	Ruutu _target(pos->GetRivi(), pos->GetSarake());
	if (vari == 0) {
		Ruutu _target(pos->GetRivi(), pos->GetSarake() + 1);
	}
	else if (vari == 1) {
		Ruutu _target(pos->GetRivi(), pos->GetSarake() - 1);
	}
	wchar_t nappi = 'S';

	Siirto siirto(_pos, _target, nappi);
	lista.push_front(siirto);
}
