#include <stdio.h>
#include <iostream>
int iErste, iZweite, iSumme, iQuotient;
double dSummeCast, dQuotientCast;

int main(){
	std::cout << "geben Sie den ersten Nummer ein"  << std::endl;
	std::cin >> iErste;
	std::cout << "geben Sie den zweiten Nummer ein " << std::endl;
	std::cin >> iZweite;

	//integers
	iSumme = iErste + iZweite;
	iQuotient = iErste/iZweite;

	std::cout << "Summe: " << iSumme << std::endl;
	std::cout << "Division: " << iQuotient << std::endl;

	//casted
	dSummeCast = double(iErste) + double(iZweite);
	dQuotientCast = double(iErste)/double(iZweite);


	std::cout << "Summe (cast): " << dSummeCast << std::endl;
	std::cout << "Division (cast): " << dQuotientCast << std::endl;
}

