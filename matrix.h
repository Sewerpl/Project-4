#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdlib> // dla rand() i srand()
#include <ctime>   // dla time()
#include <iomanip> // dla std::setw()

class matrix {
private:
    int** data;  // dynamiczna tablica do przechowywania macierzy
    int size;    // rozmiar macierzy

    void freeMemory(); // metoda pomocnicza do zwolnienia pamięci
    void allocateMemory(int n); // metoda pomocnicza do alokacji pamięci

};

#endif // MATRIX_H
