#include <stdio.h>
#include <iostream>
int iErste, iZweite, iSumme, iQuotient;

int main(){
	std::cout << "geben Sie den ersten Nummer ein"  << std::endl;
	std::cin >> iErste;
	std::cout << "geben Sie den zweiten Nummer ein " << std::endl;
	std::cin >> iZweite;

	iSumme = iErste + iZweite;
	iQuotient = iErste/iZweite;

	std::cout << "Summe: " << iSumme << std::endl;
	std::cout << "Division: " << iQuotient << std::endl;
}

