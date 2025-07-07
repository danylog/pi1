#include <iostream>
#include <vector>
#include <fstream>
#include <string>

struct Student
{
    std::string matrikelnummer;
    std::string name;
    std::string geburtsdatum;
    std::string adresse;
};

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
        std::cout << "5. Daten in eine Datei sichern\n"; // Neuer Menüpunkt
        std::cout << "0. Beenden\n";
        std::cout << "Ihre Auswahl: ";
        std::cin >> auswahl;

        switch (auswahl)
        {
        case 1:
            std::cout << "Vorwärts:" << std::endl;
            for (auto it = studenten.begin(); it != studenten.end(); ++it)
            {
                std::cout << it->matrikelnummer << ", " << it->name << ", " << it->geburtsdatum << ", " << it->adresse << std::endl;
            }
            break;
        case 2:
            std::cout << "Rückwärts:" << std::endl;
            for (auto rit = studenten.rbegin(); rit != studenten.rend(); ++rit)
            {
                std::cout << rit->matrikelnummer << ", " << rit->name << ", " << rit->geburtsdatum << ", " << rit->adresse << std::endl;
            }
            break;
        case 3:
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
            std::string dateiname;
            std::cout << "Dateiname zum Einlesen: ";
            std::cin >> dateiname;

            std::ifstream datei(dateiname);
            if (!datei)
            {
                std::cout << "Datei konnte nicht geöffnet werden!" << std::endl;
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
                    break; // Am Ende der Datei
                studenten.push_back(s);
            }
            std::cout << "Daten wurden eingelesen." << std::endl;
            break;
        }
        case 5:
        {
            std::string dateiname;
            std::cout << "Dateiname zum Speichern: ";
            std::cin >> dateiname;

            std::ofstream datei(dateiname); // Datei wird überschrieben, falls vorhanden
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
            std::cout << "Programm beendet." << std::endl;
            break;
        default:
            std::cout << "Ungueltige Auswahl!" << std::endl;
        }
    } while (auswahl != 0);

    return 0;
}
