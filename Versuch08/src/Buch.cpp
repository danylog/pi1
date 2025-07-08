/*
 * Buch.cpp
 *
 *  Created on: Jun 1, 2025
 *      Author: danylo
 */

#include "Buch.h"
#include <iostream>

// Konstruktor: ruft explizit den Konstruktor der Basisklasse Medium auf
Buch::Buch(std::string initTitel, std::string initAutor)
	: Medium(initTitel), autor(initAutor)
{
}

// Destruktor
Buch::~Buch()
{
}

// Überschriebene Ausgabefunktion
void Buch::ausgabe() const
{
	// Ausgabe der Basisklasse aufrufen
	Medium::ausgabe();
	// Zusätzlich den Autor ausgeben
	std::cout << "Autor: " << autor << std::endl;
}
