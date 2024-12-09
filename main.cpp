#include "matrix.h"
#include <iostream>

/**
 * @file main.cpp
 * @brief Program testujący działanie klasy `matrix`.
 * 
 * Plik zawiera funkcję główną, która testuje różne funkcjonalności klasy `matrix`,
 * takie jak generowanie macierzy, losowe wypełnianie oraz transponowanie.
 */

/**
 * @brief Funkcja główna programu.
 * 
 * Funkcja testuje działanie klasy `matrix`. Tworzy obiekt macierzy 5x5,
 * wypełnia go losowymi wartościami, a następnie transponuje macierz
 * i wyświetla wyniki na standardowym wyjściu.
 * 
 * @return Zwraca 0, jeśli program zakończył się poprawnie.
 */
int main() {
    // Tworzenie macierzy o rozmiarze 5x5
    matrix m1(5);
    
    std::cout << "Macierz 5x5 wypelniona losowymi liczbami:\n";
    // Wypełnienie macierzy losowymi wartościami i jej wypisanie
    m1.losuj();
    std::cout << m1;

    // Transponowanie macierzy i wyświetlenie wyniku
    std::cout << "\nPo transpozycji:\n";
    m1.dowroc();
    std::cout << m1;

    return 0;
}
