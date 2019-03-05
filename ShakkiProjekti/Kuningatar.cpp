#include "Kuningatar.h"

void Kuningatar::AnnaSiirrot(std::list<Siirto>& lista, Ruutu * pos, Asema * asema, int vari)
{
	//std::wcout << "<<<<<<KUNINGATTAREN SIIRROT>>>>>> " << std::endl;

	this->Torni::AnnaSiirrot(lista, pos, asema, vari);
	this->Lahetti::AnnaSiirrot(lista, pos, asema, vari);

	//std::wcout << "<<<<<<KUNINGATTAREN SIIRROT LOPPUU>>>>>> " << std::endl << std::endl;
}

//bool Kuningatar::GetOnkoLiikkunut()
//{
//	return false;
//}
//
//void Kuningatar::SetOnkoLiikkunut(bool liikkunut)
//{
//}
