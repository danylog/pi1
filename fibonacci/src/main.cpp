#include <iostream>


// Rekursive Funktion zur Berechnung von Fibonacci-Zahlen
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int anzahl;

    std::cout << "Gib die Anzahl der Fibonacci-Zahlen ein: ";
    std::cin >> anzahl;

    std::cout << "Fibonacci-Folge:" << std::endl;
    for (int i = 0; i < anzahl; ++i) {
        std::cout << fibonacci(i) << " ";
    }

    std::cout << std::endl;
    return 0;
}
