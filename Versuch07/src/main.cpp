#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm> // für sort und find
#include <cctype>
#include <locale>
#include "Student.h"

/**
 * @brief Entfernt führende und nachfolgende Leerzeichen aus einem String.
 *
 * @param s Referenz auf den zu bearbeitenden String.
 */
static inline void trim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch)
                                    { return !std::isspace(ch); }));
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
                         { return !std::isspace(ch); })
                .base(),
            s.end());
}

/**
 * @brief Hauptfunktion des Programms.
 *
 * Bietet ein Menü zur Verwaltung einer Studentenliste:
 * - Ausgabe vorwärts/rückwärts
 * - Löschen von Elementen
 * - Einlesen/Speichern aus/in Datei
 * - Sortieren der Liste
 *
 * @return int Rückgabewert des Programms (0 bei Erfolg)
 */
int main()
{
    std::vector<Student> studenten;

    int auswahl;
    do
    {
        std::cout << "\nMenü:\n";
        std::cout << "1. Vorwaerts ausgeben\n";
        std::cout << "2. Rueckwaerts ausgeben\n";
        std::cout << "3. Datenelement vorne loeschen\n";
        std::cout << "4. Daten aus Datei einlesen\n";
        std::cout << "5. Datenelement loeschen (nach Matrikelnummer)\n";
        std::cout << "6. Liste sortieren\n";
        std::cout << "7. Daten in eine Datei sichern\n";
        std::cout << "0. Beenden\n";
        std::cout << "Ihre Auswahl: ";
        std::cin >> auswahl;

        switch (auswahl)
        {
        case 1:
            /**
             * @brief Gibt die Studentenliste vorwärts aus.
             */
            std::cout << "Vorwärts:" << std::endl;
            for (const auto &s : studenten)
                std::cout << s << std::endl;
            break;
        case 2:
            /**
             * @brief Gibt die Studentenliste rückwärts aus.
             */
            std::cout << "Rückwärts:" << std::endl;
            for (auto rit = studenten.rbegin(); rit != studenten.rend(); ++rit)
                std::cout << *rit << std::endl;
            break;
        case 3:
            /**
             * @brief Löscht das erste Element der Studentenliste.
             */
            if (!studenten.empty())
            {
                studenten.erase(studenten.begin());
                std::cout << "Erster Student wurde geloescht." << std::endl;
            }
            else
            {
                std::cout << "Liste ist leer, nichts zu loeschen." << std::endl;
            }
            break;
        case 4:
        {
            /**
             * @brief Liest Studentendaten aus einer Datei ein.
             */
            std::string dateiname;
            std::cout << "Dateiname zum Einlesen: ";
            std::cin >> dateiname;

            std::ifstream datei(dateiname);
            if (!datei)
            {
                std::cout << "Datei konnte nicht geöffnet werden!" << std::endl;
                break;
            }

            studenten.clear();

            while (!datei.eof())
            {
                Student s;
                std::getline(datei, s.matrikelnummer);
                trim(s.matrikelnummer); // <--- trimmen!
                std::getline(datei, s.name);
                std::getline(datei, s.geburtsdatum);
                std::getline(datei, s.adresse);
                if (s.matrikelnummer.empty())
                    break;
                studenten.push_back(s);
            }
            std::cout << "Daten wurden eingelesen." << std::endl;
            break;
        }
        case 5:
        {
            /**
             * @brief Löscht einen Studenten anhand der Matrikelnummer.
             */
            std::string matrikel;
            std::cout << "Matrikelnummer des zu löschenden Studenten: ";
            std::cin >> matrikel;
            trim(matrikel);

            auto it = std::find_if(studenten.begin(), studenten.end(),
                                   [&matrikel](const Student &s)
                                   {
                                       std::string m = s.matrikelnummer;
                                       trim(m);
                                       return m == matrikel;
                                   });

            if (it != studenten.end())
            {
                std::cout << "Gefundener Student: " << *it << std::endl;
                studenten.erase(it);
                std::cout << "Student wurde gelöscht. Verbleibende Studenten:" << std::endl;
                for (const auto &s : studenten)
                    std::cout << s << std::endl;
            }
            else
            {
                std::cout << "Student mit Matrikelnummer " << matrikel << " nicht gefunden." << std::endl;
            }
            break;
        }
        case 6:
            /**
             * @brief Sortiert die Studentenliste.
             */
            std::sort(studenten.begin(), studenten.end());
            std::cout << "Liste wurde sortiert:" << std::endl;
            for (const auto &s : studenten)
                std::cout << s << std::endl;
            break;
        case 7:
        {
            /**
             * @brief Speichert die Studentenliste in eine Datei.
             */
            std::string dateiname;
            std::cout << "Dateiname zum Speichern: ";
            std::cin >> dateiname;

            std::ofstream datei(dateiname);
            if (!datei)
            {
                std::cout << "Datei konnte nicht zum Schreiben geöffnet werden!" << std::endl;
                break;
            }

            for (const auto &s : studenten)
            {
                datei << s.matrikelnummer << std::endl;
                datei << s.name << std::endl;
                datei << s.geburtsdatum << std::endl;
                datei << s.adresse << std::endl;
            }
            std::cout << "Daten wurden gespeichert." << std::endl;
            break;
        }
        case 0:
            /**
             * @brief Beendet das Programm.
             */
            std::cout << "Programm beendet." << std::endl;
            break;
        default:
            std::cout << "Ungueltige Auswahl!" << std::endl;
        }
    } while (auswahl != 0);

    return 0;
}
