#include "Torni.h"
#include "Asema.h"

void Torni::AnnaSiirrot(std::list<Siirto>& lista, Ruutu* pos, Asema* asema, int vari)
{
	//std::wcout << "<<<<<<TORNIN SIIRROT>>>>>> " << std::endl;

	int x = pos->GetSarake();
	int y = pos->GetRivi();
	Ruutu _pos(x, y);
	/*wchar_t nappi;

	if (asema->lauta[x][y]->GetKoodi() == VD || asema->lauta[x][y]->GetKoodi() == MD) {
		nappi = 'D';
	}
	else 
	{
		nappi = 'T';
	}*/

	
	//std::wcout << "<AnnaSiirrot>AlkuPositio x : " << x << " <AnnaSiirrot>AlkuPositio y : " <<  y << std::endl;
	
	//std::wcout << "Liikkeet Oikealle: " << std::endl;
	//Tornien liike oikealle
	for (int i = 1; i <= 7; i++)
	{
		//Kohteeksi asetetaan seuraava positio
		Ruutu _target(x + i, y);
		int tx = x + i;

		//std::wcout << "target positio x : " << tx << " target positio y : " << y << std::endl;

		// mennäänkö yli laudan oikeastareunasta?
		if (tx > 7) {
			//std::wcout << "Laita tuli vastaan" << std::endl;
			break;
		}

		//jos seuraava ruutu oikealla ei ole tyhjä ja jos väri ei ole sama kuin liikkelle lähtevän nappulan väri niin syödään kyseinen
		if (asema->lauta[tx][y] != nullptr && asema->lauta[tx][y]->GetVari() != vari) 
		{		
			Siirto syoOikealle(_pos, _target);
			lista.push_back(syoOikealle);
			//std::wcout << "Syö nappi oikealle : "; syoOikealle.TulostaRuudut();
			break;
		}

		//ei voida liikkua oikealle koska oma nappi on edessä!
		else if (asema->lauta[tx][y] != nullptr && asema->lauta[tx][y]->GetVari() == vari)
		{
			//std::wcout << "oikealla on oma nappi " << std::endl;
			break;
		}

		//muuten liikkuu oikealle tallennetaan mahdollisiin siirtoihin ja jatka katsomaan seuraavaa ruutua
		else if (asema->lauta[tx][y] == nullptr)
		{		
			Siirto liikuOikealle(_pos, _target);
			lista.push_back(liikuOikealle);
			//std::wcout << "Liiku Oikealle : "; liikuOikealle.TulostaRuudut();
			continue;
		}
	}

	//std::wcout << "Liikkeet Vasemmalle: " << std::endl;
	//Tornien liike vasemmalle
	for (int i = 1; i <= 7; i++)
	{
			//Kohteeksi asetetaan seuraava positio
			Ruutu _target(x - i, y);
			int tx = x - i;

			//std::wcout << "target positio x : " << tx << " target positio y : " << y << std::endl;

			//mennäänkö yli laudan vasemmastareunasta?
			if (tx < 0) 
			{
				//std::wcout << "Laita tuli vastaan" << std::endl;
				break;
			}

			//jos seuraava ruutu vasemmalla ei ole tyhjä ja jos väri ei ole sama kuin liikkelle lähtevän nappulan väri niin syödään kyseinen ja lopeta liike
			if (asema->lauta[tx][y] != nullptr && asema->lauta[tx][y]->GetVari() != vari)
			{
				Siirto syoVasemmalle(_pos, _target);
				lista.push_back(syoVasemmalle);
				//std::wcout << "Syö nappi Vasemmalle : "; syoVasemmalle.TulostaRuudut();
				break;
			}

			//ei voida liikkua vasemmalle koska oma nappi on edessä!
			else if (asema->lauta[tx][y] != nullptr && asema->lauta[tx][y]->GetVari() == vari)
			{
				//std::wcout << "Vasemmalla on oma nappi " << std::endl;
				break;
			}

			//muuten liikkuu vasemmalle tallennetaan mahdollisiin siirtoihin ja jatka katsomaan seuraavaa ruutua
			else if (asema->lauta[tx][y] == nullptr)
			{
				Siirto liikuVasemmalle(_pos, _target);
				lista.push_back(liikuVasemmalle);
				//std::wcout << "Liiku Vasemmalle : "; liikuVasemmalle.TulostaRuudut();
				continue;
			}
	}
	
	//std::wcout << "Liikkeet Ylös: " << std::endl;
	//Tornien liike Ylös
	for (int i = 1; i <= 7; i++)
	{
	
			//Kohteeksi asetetaan seuraava positio
			Ruutu _target(x, y + i);
			int ty = y + i;

			// mennäänkö yli laudan yläreunasta?
			if (ty > 7) 
			{
				//std::wcout << "Laita tuli vastaan" << std::endl;
				break;
			}

			//jos seuraava ruutu ylhäällä ei ole tyhjä ja jos väri ei ole sama kuin liikkelle lähtevän nappulan väri niin syödään kyseinen ja lopetetaan liike
			if (asema->lauta[x][ty] != nullptr && asema->lauta[x][ty]->GetVari() != vari)
			{
				Siirto syoYlos(_pos, _target);
				lista.push_back(syoYlos);
				//std::wcout << "Syö nappi Ylös : "; syoYlos.TulostaRuudut();
				break;
			}
			//ei voida liikkua ylös koska oma nappi on edessä!
			else if (asema->lauta[x][ty] != nullptr && asema->lauta[x][ty]->GetVari() == vari)
			{
				//std::wcout << "Yläpuolella on oma nappi " << std::endl;
				break;
			}
			//muuten liikkuu ylös tallennetaan mahdollisiin siirtoihin ja jatketaan katsomaan seuraavaa ruutua
			else if (asema->lauta[x][ty] == nullptr)
			{
				Siirto liikuYlos(_pos, _target);
				lista.push_back(liikuYlos);
				//std::wcout << "Liiku Ylös : "; liikuYlos.TulostaRuudut();
				continue;
			}
	}

	//std::wcout << "Liikkeet Alas: " << std::endl;
	//Tornien liike alas
	for (int i = 1; i <= 7; i++)
	{
	
		//Kohteeksi asetetaan seuraava positio
		Ruutu _target(x, y - i);
		int ty = y - i;

		// mennäänkö yli laudan alareunasta?
		if (ty < 0) 
		{
			//std::wcout << "Laita tuli vastaan" << std::endl;
			break;
		}

		//jos seuraava ruutu alhaalla ei ole tyhjä ja jos väri ei ole sama kuin liikkelle lähtevän nappulan väri niin syödään kyseinen ja lopetetaan liike
		if (asema->lauta[x][ty] != nullptr && asema->lauta[x][ty]->GetVari() != vari)
		{
			Siirto syoAlas(_pos, _target);
			lista.push_back(syoAlas);
			//std::wcout << "Syö nappi Alas : "; syoAlas.TulostaRuudut();
			break;
		}

		//ei voida liikkua alas koska oma nappi on edessä!
		else if (asema->lauta[x][ty] != nullptr && asema->lauta[x][ty]->GetVari() == vari)
		{
			//std::wcout << "Alapuolella on oma nappi " << std::endl;
			break;
		}

		//muuten liikkuu alas tallennetaan mahdollisiin siirtoihin ja jatketaan katsomaan seuraavaa ruutua
		else if (asema->lauta[x][ty] == nullptr)
		{		
			Siirto liikuVasemmalle(_pos, _target);
			lista.push_back(liikuVasemmalle);
			//std::wcout << "Liiku Alas : "; liikuVasemmalle.TulostaRuudut();
			continue;
		}
	}


	//std::wcout << "<<<<<<TORNIN SIIRROT LOPPUU>>>>>> " << std::endl << std::endl;
}

//bool Torni::GetOnkoLiikkunut()
//{
//	return false;
//}
//
//void Torni::SetOnkoLiikkunut(bool liikkunut)
//{
//}
