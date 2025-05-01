#include <stdio.h>
#include <iostream>
int iErste, iZweite, iSumme, iQuotient;
double dSummeCast, dQuotientCast;
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
}

