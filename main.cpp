#include "matrix.h"
#include <iostream>

int main() {
    // Testowanie klasy matrix
    matrix m1(5);
    std::cout << "Macierz 5x5 wypelniona losowymi liczbami:\n";
    m1.losuj();
    std::cout << m1;

    std::cout << "\nPo transpozycji:\n";
    m1.dowroc();
    std::cout << m1;

    return 0;
}