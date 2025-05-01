/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

struct Person{
		std::string sNachname;
		std::string sVorname;
		int iGeburtsjahr;
		int iAlter;
};

void vDisplayData(Person p){
	std::cout << p.sNachname
			<<std::endl <<p.sVorname
			<<std::endl<<p.iGeburtsjahr
			<<std::endl <<p.iAlter
			<<std::endl;
}

int main()
{
	Person nBenutzer;
	std::cout << "Nachname?" <<std::endl;
	std::cin >> nBenutzer.sNachname;
	std::cout << "Vorname?" <<std::endl;
	std::cin >> nBenutzer.sVorname;
	std::cout << "Geburtsjahr?" <<std::endl;
	std::cin >> nBenutzer.iGeburtsjahr;
	std::cout << "Alter?" <<std::endl;
	std::cin >> nBenutzer.iAlter;


	std::cout << "Benutzerdata:" <<std::endl;
	vDisplayData(nBenutzer);

	Person nKopieEinzeln;

	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.sVorname = nBenutzer.sVorname;
	nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	nKopieEinzeln.iAlter = nBenutzer.iAlter;

	std::cout <<"Kopie Einzeln:" <<std::endl;
	vDisplayData(nKopieEinzeln);



    Person nKopieGesamt = nBenutzer;

    std::cout <<"Kopie Gesamt:" <<std::endl;

    vDisplayData(nKopieGesamt);



    return 0;
}
