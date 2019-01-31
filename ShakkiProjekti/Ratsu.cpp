#include "Ratsu.h"
#include "Asema.h"

void Ratsu::AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari)
{
	wchar_t nappi = 'R';
	Ruutu _pos(pos->GetRivi(), pos->GetSarake());
	Ruutu _target(pos->GetRivi(), pos->GetSarake());

	//Ratsu YlösOikealle
	if (asema->lauta[pos->GetRivi() + 1][pos->GetSarake() + 2] == nullptr) {
		Ruutu _target(pos->GetRivi() + 1, pos->GetSarake() + 2);
		Siirto ylosOikea(_pos, _target, nappi);
		lista.push_front(ylosOikea);
	}
	else if (asema->lauta[pos->GetRivi() + 1][pos->GetSarake() + 2]->GetVari() != vari) {
		Ruutu _target(pos->GetRivi() + 1, pos->GetSarake() + 2);
		Siirto syoYlosOikea(_pos, _target, nappi);
		lista.push_front(syoYlosOikea);
	}

	//Ratsu YlösVasen
	if (asema->lauta[pos->GetRivi() - 1][pos->GetSarake() + 2] == nullptr) {
		Ruutu _target(pos->GetRivi() - 1, pos->GetSarake() + 2);
		Siirto ylosVasen(_pos, _target, nappi);
		lista.push_front(ylosVasen);
	}
	else if (asema->lauta[pos->GetRivi() - 1][pos->GetSarake() + 2]->GetVari() != vari) {
		Ruutu _target(pos->GetRivi() - 1, pos->GetSarake() + 2);
		Siirto syoYlosVasen(_pos, _target, nappi);
		lista.push_front(syoYlosVasen);
	}

	//Ratsu AlasVasen
	if (asema->lauta[pos->GetRivi() - 1][pos->GetSarake() - 2] == nullptr) {
		Ruutu _target(pos->GetRivi() - 1, pos->GetSarake() - 2);
		Siirto alasVasen(_pos, _target, nappi);
		lista.push_front(alasVasen);
	}
	else if (asema->lauta[pos->GetRivi() - 1][pos->GetSarake() - 2]->GetVari() != vari) {
		Ruutu _target(pos->GetRivi() - 1, pos->GetSarake() - 2);
		Siirto syoAlasVasen(_pos, _target, nappi);
		lista.push_front(syoAlasVasen);
	}

	//Ratsu AlasOikea
	if (asema->lauta[pos->GetRivi() + 1][pos->GetSarake() - 2] == nullptr) {
		Ruutu _target(pos->GetRivi() + 1, pos->GetSarake() - 2);
		Siirto alasOikea(_pos, _target, nappi);
		lista.push_front(alasOikea);
	}
	else if (asema->lauta[pos->GetRivi() + 1][pos->GetSarake() - 2]->GetVari() != vari) {
		Ruutu _target(pos->GetRivi() + 1, pos->GetSarake() - 2);
		Siirto syoAlasOikea(_pos, _target, nappi);
		lista.push_front(syoAlasOikea);
	}

	//Ratsu OikealleYlös
	if (asema->lauta[pos->GetRivi() + 2][pos->GetSarake() + 1] == nullptr) {
		Ruutu _target(pos->GetRivi() + 2, pos->GetSarake() + 1);
		Siirto oikeaYlos(_pos, _target, nappi);
		lista.push_front(oikeaYlos);
	}
	else if (asema->lauta[pos->GetRivi() + 2][pos->GetSarake() + 1]->GetVari() != vari) {
		Ruutu _target(pos->GetRivi() + 2, pos->GetSarake() + 1);
		Siirto syoOikeaYlos(_pos, _target, nappi);
		lista.push_front(syoOikeaYlos);
	}

	//Ratsu VasenYlös
	if (asema->lauta[pos->GetRivi() - 2][pos->GetSarake() + 1] == nullptr) {
		Ruutu _target(pos->GetRivi() - 2, pos->GetSarake() + 1);
		Siirto vasenYlos(_pos, _target, nappi);
		lista.push_front(vasenYlos);
	}
	else if (asema->lauta[pos->GetRivi() - 2][pos->GetSarake() + 1]->GetVari() != vari) {
		Ruutu _target(pos->GetRivi() - 2, pos->GetSarake() + 1);
		Siirto syoVasenYlos(_pos, _target, nappi);
		lista.push_front(syoVasenYlos);
	}

	//Ratsu VasenAlas
	if (asema->lauta[pos->GetRivi() - 2][pos->GetSarake() -1] == nullptr) {
		Ruutu _target(pos->GetRivi() - 2, pos->GetSarake() -1);
		Siirto vasenAlas(_pos, _target, nappi);
		lista.push_front(vasenAlas);
	}
	else if (asema->lauta[pos->GetRivi() - 2][pos->GetSarake() - 1]->GetVari() != vari) {
		Ruutu _target(pos->GetRivi() - 2, pos->GetSarake() - 1);
		Siirto syoVasenAlas(_pos, _target, nappi);
		lista.push_front(syoVasenAlas);
	}

	//Ratsu OikeaAlas
	if (asema->lauta[pos->GetRivi() + 2][pos->GetSarake() - 1] == nullptr) {
		Ruutu _target(pos->GetRivi() + 2, pos->GetSarake() - 1);
		Siirto oikeaAlas(_pos, _target, nappi);
		lista.push_front(oikeaAlas);
	}
	else if (asema->lauta[pos->GetRivi() + 2][pos->GetSarake() - 1]->GetVari() != vari) {
		Ruutu _target(pos->GetRivi() + 2, pos->GetSarake() - 1);
		Siirto syoOikeaAlas(_pos, _target, nappi);
		lista.push_front(syoOikeaAlas);
	}
	
}
