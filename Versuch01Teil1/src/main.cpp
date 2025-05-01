#include <stdio.h>
#include <iostream>


int iErste, iZweite, iSumme, iQuotient;
double dSummeCast, dQuotientCast;
int iFeld[2];
int iFeldB[2][3];

std::string sVorname, sNachname, sVornameNachname, sNachnameVorname;

int main(){
	std::cout << "geben Sie den ersten Nummer ein"  << std::endl;
	std::cin >> iErste;
	std::cout << "geben Sie den zweiten Nummer ein " << std::endl;
	std::cin >> iZweite;


	//integers (1.6.1.1)
	iSumme = iErste + iZweite;
	iQuotient = iErste/iZweite;

	std::cout << "Summe: " << iSumme << std::endl;
	std::cout << "Division: " << iQuotient << std::endl;


	//casted (1.6.1.3)
	dSummeCast = double(iErste) + double(iZweite);
	dQuotientCast = double(iErste)/double(iZweite);




	//Name (1.6.1.4)
	std::cout << "Summe (cast): " << dSummeCast << std::endl;
	std::cout << "Division (cast): " << dQuotientCast << std::endl;


	std::cout << "Geben Sie Ihre Vornamen ein" << std::endl;
	std::cin >> sVorname;
	std::cout << "Geben Sie Ihre Nachnamen ein" << std::endl;
	std::cin >> sNachname;

	sVornameNachname = sVorname + " " + sNachname;
	sNachnameVorname = sNachname + ", " + sVorname;

	std::cout << sVornameNachname << std::endl;
	std::cout << sNachnameVorname <<std::endl;


	//Felder a
	iFeld[0] = 1;
	iFeld[1] = 2;

	for (int i = 0; i<(sizeof(iFeld)/sizeof(iFeld[0])); i++){
	std::cout << iFeld[i] << std::endl;
	}

	//Felder b
	int o = 1;
	for (int i=0; i<2; i++){
		for(int a=0; a<3; a++){
			iFeldB[i][a] = o;
			std::cout << o << " ";
			o++;
		}
		std::cout << std::endl;
	}


	//konstante

	const int iZweite = 1;

	std::cout << iZweite;




}

