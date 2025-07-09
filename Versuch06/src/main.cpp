#include <iostream>
#include <vector>
#include <fstream>
#include <string>

/**
 * @file main.cpp
 * @brief Verwaltung einer Studierendenliste mit STL-Methoden.
 */

/**
 * @brief Struktur für Studierende.
 */
struct Student
{
    std::string matrikelnummer; ///< Matrikelnummer des Studierenden
    std::string name;           ///< Name des Studierenden
    std::string geburtsdatum;   ///< Geburtsdatum des Studierenden
    std::string adresse;        ///< Adresse des Studierenden
};

/**
 * @brief Gibt einen Studenten auf der Konsole aus.
 * @param s Student, der ausgegeben werden soll
 */
void printStudent(const Student &s)
{
    std::cout << s.matrikelnummer << ", " << s.name << ", " << s.geburtsdatum << ", " << s.adresse << std::endl;
}

/**
 * @brief Hauptfunktion. Zeigt ein Menü zur Verwaltung der Studierendenliste.
 * @return int Rückgabewert des Programms
 */
int main()
{
    std::vector<Student> studenten; ///< Vektor zur Speicherung der Studierenden

    int auswahl;
    do
    {
        std::cout << "\nMenü:\n";
        std::cout << "1. Vorwärts ausgeben\n";
        std::cout << "2. Rückwärts ausgeben\n";
        std::cout << "3. Datenelement vorne löschen\n";
        std::cout << "4. Daten aus Datei einlesen\n";
        std::cout << "5. Element an Position einfügen\n";
        std::cout << "6. Element an Position löschen\n";
        std::cout << "7. Daten in eine Datei sichern\n";
        std::cout << "0. Beenden\n";
        std::cout << "Ihre Auswahl: ";
        std::cin >> auswahl;

        switch (auswahl)
        {
        case 1: ///< Gibt alle Studierenden vorwärts aus.
            if (studenten.empty())
            {
                std::cout << "Liste ist leer.\n";
                break;
            }
            std::cout << "Vorwärts:\n";
            for (auto it = studenten.begin(); it != studenten.end(); ++it)
                printStudent(*it);
            break;
        case 2: ///< Gibt alle Studierenden rückwärts aus.
            if (studenten.empty())
            {
                std::cout << "Liste ist leer.\n";
                break;
            }
            std::cout << "Rückwärts:\n";
            for (auto rit = studenten.rbegin(); rit != studenten.rend(); ++rit)
                printStudent(*rit);
            break;
        case 3: ///< Löscht das erste Element der Liste.
            if (studenten.empty())
            {
                std::cout << "Liste ist leer, nichts zu löschen.\n";
            }
            else
            {
                studenten.erase(studenten.begin());
                std::cout << "Erstes Element wurde gelöscht.\n";
            }
            break;
        case 4: ///< Liest Studierendendaten aus einer Datei ein.
        {
            std::string dateiname;
            std::cout << "Dateiname zum Einlesen: ";
            std::cin >> dateiname;
            std::ifstream datei(dateiname);
            if (!datei)
            {
                std::cout << "Datei konnte nicht geöffnet werden!\n";
                break;
            }
            studenten.clear(); // Vorherige Daten löschen
            while (!datei.eof())
            {
                Student s;
                std::getline(datei, s.matrikelnummer);
                std::getline(datei, s.name);
                std::getline(datei, s.geburtsdatum);
                std::getline(datei, s.adresse);
                if (s.matrikelnummer.empty())
                    break;
                studenten.push_back(s); // STL push_back
            }
            std::cout << "Daten wurden eingelesen.\n";
            break;
        }
        case 5: ///< Fügt ein Element an einer bestimmten Position ein.
        {
            Student s;
            std::cout << "Matrikelnummer: ";
            std::cin.ignore();
            std::getline(std::cin, s.matrikelnummer);
            std::cout << "Name: ";
            std::getline(std::cin, s.name);
            std::cout << "Geburtsdatum: ";
            std::getline(std::cin, s.geburtsdatum);
            std::cout << "Adresse: ";
            std::getline(std::cin, s.adresse);
            size_t pos;
            std::cout << "Position zum Einfügen (0-" << studenten.size() << "): ";
            std::cin >> pos;
            if (pos > studenten.size())
                pos = studenten.size();
            studenten.insert(studenten.begin() + pos, s); // STL insert
            std::cout << "Element eingefügt.\n";
            break;
        }
        case 6: ///< Löscht ein Element an einer bestimmten Position.
        {
            if (studenten.empty())
            {
                std::cout << "Liste ist leer, nichts zu löschen.\n";
                break;
            }
            size_t pos;
            std::cout << "Position zum Löschen (0-" << studenten.size() - 1 << "): ";
            std::cin >> pos;
            if (pos >= studenten.size())
            {
                std::cout << "Ungültige Position.\n";
                break;
            }
            studenten.erase(studenten.begin() + pos); // STL erase
            std::cout << "Element gelöscht.\n";
            break;
        }
        case 7: ///< Speichert die Studierendendaten in eine Datei.
        {
            if (studenten.empty())
            {
                std::cout << "Liste ist leer, nichts zu speichern.\n";
                break;
            }
            std::string dateiname;
            std::cout << "Dateiname zum Speichern: ";
            std::cin >> dateiname;
            std::ofstream datei(dateiname);
            if (!datei)
            {
                std::cout << "Datei konnte nicht zum Schreiben geöffnet werden!\n";
                break;
            }
            for (const auto &s : studenten)
            {
                datei << s.matrikelnummer << "\n"
                      << s.name << "\n"
                      << s.geburtsdatum << "\n"
                      << s.adresse << "\n";
            }
            std::cout << "Daten wurden gespeichert.\n";
            break;
        }
        case 0: ///< Beendet das Programm.
            std::cout << "Programm beendet.\n";
            break;
        default:
            std::cout << "Ungültige Auswahl!\n";
        }
    } while (auswahl != 0);

    return 0;
}