#include "Lahetti.h"
#include "Asema.h"

void Lahetti::AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari)
{

	std::wcout << "<<<<<<LÄHETIN SIIRROT>>>>>> " << std::endl;

	wchar_t nappi = 'L';
	int x = pos->GetSarake();
	int y = pos->GetRivi();
	Ruutu _pos(x, y);
	std::wcout << "<AnnaSiirrot>AlkuPositio x : " << x << " <AnnaSiirrot>AlkuPositio y : " << y << std::endl;

	std::wcout << "Liikkeet Oikealle Yläviistoon: " << std::endl;
	
	//L�hetin liike oikealle yl�sviistoon
	for (int i = 1; i <= 7; i++)
	{
		//Kohteeksi asetetaan seuraava positio
		int tx = x + i;
		int ty = y + i;
		Ruutu _target(tx, ty);

		std::wcout << "target positio x : " << tx << " target positio y : " << ty << std::endl;

		// mennäänkö yli laudan oikeastareunasta tai yläreunasta?
		if (tx > 7 || ty > 7) {
			std::wcout << "Laita tuli vastaan" << std::endl;
			break;
		}

		//jos seuraava ruutu oikeassa yläviistossa ei ole tyhjä ja jos väri ei ole sama kuin liikkelle lähtevän nappulan väri niin syödään kyseinen
		if (asema->lauta[tx][ty] != nullptr && asema->lauta[tx][ty]->GetVari() != vari)
		{
			Siirto syoOikealleYlos(_pos, _target, nappi);
			lista.push_back(syoOikealleYlos);
			std::wcout << "Syö nappi Oikea yläviisto : "; syoOikealleYlos.TulostaRuudut();
			break;
		}

		//ei voida liikkua oikeaan yläviistoon koska oma nappi on edessä!
		else if (asema->lauta[tx][ty] != nullptr && asema->lauta[tx][ty]->GetVari() == vari)
		{
			std::wcout << "Oikeassa yläviistossa on oma nappi " << std::endl;
			break;
		}

		//muuten liikkuu oikeaan yläviistoon tallennetaan mahdollisiin siirtoihin ja jatka katsomaan seuraavaa ruutua
		else
		{
			Siirto liikuOikealleYlos(_pos, _target, nappi);
			lista.push_back(liikuOikealleYlos);
			std::wcout << "Liiku Oikeaan yläviistoon : "; liikuOikealleYlos.TulostaRuudut();
			continue;
		}
	}

	std::wcout << "Liikkeet Vasemmalle Yläviistoon: " << std::endl;
	//L�hetin liike vasemmalle yl�sviistoon
	for (int i = 1; i <= 7; i++)
	{
		//Kohteeksi asetetaan seuraava positio
		int tx = x - i;
		int ty = y + i;
		Ruutu _target(tx, ty);

		std::wcout << "target positio x : " << tx << " target positio y : " << ty << std::endl;

		// mennäänkö yli laudan vasemmastareunasta tai yläreunasta?
		if (tx < 0 || ty > 7) {
			std::wcout << "Laita tuli vastaan" << std::endl;
			break;
		}

		//jos seuraava ruutu Vasemmassa yläviistossa ei ole tyhjä ja jos väri ei ole sama kuin liikkelle lähtevän nappulan väri niin syödään kyseinen
		if (asema->lauta[tx][ty] != nullptr && asema->lauta[tx][ty]->GetVari() != vari)
		{
			Siirto syoVasemmalleYlos(_pos, _target, nappi);
			lista.push_back(syoVasemmalleYlos);
			std::wcout << "Syö nappi Vasen yläviisto : "; syoVasemmalleYlos.TulostaRuudut();
			break;
		}

		//ei voida liikkua Vasemmassa yläviistoon koska oma nappi on edessä!
		else if (asema->lauta[tx][ty] != nullptr && asema->lauta[tx][ty]->GetVari() == vari)
		{
			std::wcout << "Vasemmassa yläviistossa on oma nappi " << std::endl;
			break;
		}

		//muuten liikkuu Vasempaan yläviistoon tallennetaan mahdollisiin siirtoihin ja jatka katsomaan seuraavaa ruutua
		else
		{
			Siirto liikuVasemmalleYlos(_pos, _target, nappi);
			lista.push_back(liikuVasemmalleYlos);
			std::wcout << "Liiku Vasempaan yläviistoon : "; liikuVasemmalleYlos.TulostaRuudut();
			continue;
		}
	}

	std::wcout << "Liikkeet Vasemmalle Alasviistoon: " << std::endl;
	//L�hetin liike vasemmalle alasviistoon
	for (int i = 1; i <= 7; i++)
	{
		//Kohteeksi asetetaan seuraava positio
		int tx = x - i;
		int ty = y - i;
		Ruutu _target(tx, ty);

		std::wcout << "target positio x : " << tx << " target positio y : " << ty << std::endl;

		//mennäänkö yli laudan vasemmastareunasta tai alareunasta?
		if (tx < 0 || ty < 0) {
			std::wcout << "Laita tuli vastaan" << std::endl;
			break;
		}

		//jos seuraava ruutu Vasemmassa-alaviistossa ei ole tyhjä ja jos väri ei ole sama kuin liikkelle lähtevän nappulan väri niin syödään kyseinen
		if (asema->lauta[tx][ty] != nullptr && asema->lauta[tx][ty]->GetVari() != vari)
		{
			Siirto syoVasemmalleAlas(_pos, _target, nappi);
			lista.push_back(syoVasemmalleAlas);
			std::wcout << "Syö nappi Vasen alaviisto : "; syoVasemmalleAlas.TulostaRuudut();
			break;
		}

		//ei voida liikkua Vasemmassa-alaviistoon koska oma nappi on edessä!
		else if (asema->lauta[tx][ty] != nullptr && asema->lauta[tx][ty]->GetVari() == vari)
		{
			std::wcout << "Vasemmassa alaviistossa on oma nappi " << std::endl;
			break;
		}

		//muuten liikkuu Vasempaan-alaviistoon tallennetaan mahdollisiin siirtoihin ja jatka katsomaan seuraavaa ruutua
		else
		{
			Siirto liikuVasemmalleAlas(_pos, _target, nappi);
			lista.push_back(liikuVasemmalleAlas);
			std::wcout << "Liiku Vasempaan alaviistoon : "; liikuVasemmalleAlas.TulostaRuudut();
			continue;
		}
	}

	//L�hetin liike oikealle alas viistoon
	/*
	 -  -  -  -  -  -  -  -  6
	 -  -  -  -  -  -  -  -  5
	 -  L -  -  -  -  -  -   4
	 -  -  *  -  -  -  -  -  3
	 -  -  -  *  -  -  -  -  2
	 -  -  -  -  *  -  -  -  1
	 -  -  -  -  -  *  -  -  0
						 ? ty < 0
	 */

	std::wcout << "Liikkeet Oikealle Alaviistoon: " << std::endl;
	//L�hetin liike Oikealle alasviistoon
	for (int i = 1; i <= 7; i++)
	{
		//Kohteeksi asetetaan seuraava positio
		int tx = x + i;
		int ty = y - i;
		Ruutu _target(tx, ty);

		std::wcout << "target positio x : " << tx << " target positio y : " << ty << std::endl;

		//mennäänkö yli laudan oikeastareunasta tai alareunasta?
		if (tx > 7 || ty < 0) {
			std::wcout << "Laita tuli vastaan" << std::endl;
			break;
		}

		//jos seuraava ruutu Oikeassa-alaviistossa ei ole tyhjä ja jos väri ei ole sama kuin liikkelle lähtevän nappulan väri niin syödään kyseinen
		if (asema->lauta[tx][ty] != nullptr && asema->lauta[tx][ty]->GetVari() != vari)
		{
			Siirto syoOikealleAlas(_pos, _target, nappi);
			lista.push_back(syoOikealleAlas);
			std::wcout << "Syö nappi Oikea-alaviisto : "; syoOikealleAlas.TulostaRuudut();
			break;
		}

		//ei voida liikkua Oikeaan alaviistoon koska oma nappi on edessä!
		else if (asema->lauta[tx][ty] != nullptr && asema->lauta[tx][ty]->GetVari() == vari)
		{
			std::wcout << "Oikeassa-alaviistossa on oma nappi " << std::endl;
			break;
		}

		//muuten liikkuu Oikeaan alaviistoon tallennetaan mahdollisiin siirtoihin ja jatka katsomaan seuraavaa ruutua
		else
		{
			Siirto liikuOikealleAlas(_pos, _target, nappi);
			lista.push_back(liikuOikealleAlas);
			std::wcout << "Liiku Oikeaan alaviistoon : "; liikuOikealleAlas.TulostaRuudut();
			continue;
		}
	}

	std::wcout << "<<<<<<LÄHETIN SIIRROT LOPPUU>>>>>> " << std::endl << std::endl;
}