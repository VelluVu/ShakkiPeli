#include "Kunigatar.h"

void Kuningatar::AnnaSiirrot(std::list<Siirto>& lista, Ruutu * pos, Asema * asema, int vari)
{
	std::wcout << "<<<<<<KUNINGATTAREN SIIRROT>>>>>> " << std::endl;

	Torni::AnnaSiirrot(lista, pos, asema, vari);
	Lahetti::AnnaSiirrot(lista, pos, asema, vari);

	std::wcout << "<<<<<<KUNINGATTAREN SIIRROT LOPPUU>>>>>> " << std::endl << std::endl;
}
