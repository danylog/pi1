///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
//
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////



#include <iostream>
#include <string>

using namespace std;

string verschluesseln(char schluessel[2][26], string wort)
{
	string verschluesselt = "";

	for (size_t i = 0; i < wort.length(); ++i)
	{
		char buchstabe = wort[i];
		// Suche die Position des Buchstabens im Klartext-Alphabet
		for (int j = 0; j < 26; ++j)
		{
			if (schluessel[0][j] == buchstabe)
			{
				verschluesselt += schluessel[1][j];
				break;
			}
		}
	}

	return verschluesselt;
}

string entschluesseln(char schluessel[2][26], string wort)
{
	string entschluesselt = "";

	for (size_t i = 0; i < wort.length(); ++i)
	{
		char buchstabe = wort[i];
		// Suche die Position des Buchstabens im Geheimtext-Alphabet
		for (int j = 0; j < 26; ++j)
		{
			if (schluessel[1][j] == buchstabe)
			{
				entschluesselt += schluessel[0][j];
				break;
			}
		}
	}

	return entschluesselt;
}

int main()
{
	char schluessel[2][26];

	// Zeile 1: Klartext-Alphabet A-Z
	for (int i = 0; i < 26; ++i)
	{
		schluessel[0][i] = 'A' + i;
	}

	// Zeile 2: Geheimtext-Alphabet (Permutation)
	string geheim = "QWERTYUIOPASDFGHJKLZXCVBNM";
	for (int i = 0; i < 26; ++i)
	{
		schluessel[1][i] = geheim[i];
	}

	// Benutzereingabe
	string klartext;
	cout << "Bitte geben Sie ein Wort in Großbuchstaben ein: ";
	cin >> klartext;

	// Verschlüsseln
	string verschluesselt = verschluesseln(schluessel, klartext);
	cout << "Klartext:      " << klartext << endl;
	cout << "Verschluesselt:" << verschluesselt << endl;

	// Entschlüsseln
	string entschluesselt = entschluesseln(schluessel, verschluesselt);
	cout << "Entschluesselt:" << entschluesselt << endl;

	return 0;
}
