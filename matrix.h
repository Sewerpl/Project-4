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

public:
    // Konstruktor i destruktor
    matrix();
    matrix(int n);
    matrix(int n, int* t);
    matrix(const matrix& m); // konstruktor kopiujący
    ~matrix();

    // Metody zarządzania pamięcią
    matrix& alokuj(int n);

    // Metody dostępu i modyfikacji elementów
    matrix& wstaw(int x, int y, int wartosc);
    int pokaz(int x, int y) const;

        // Operacje na macierzach
    matrix& dowroc();
    matrix& losuj();
    matrix& losuj(int x);
    matrix& diagonalna(int* t);
    matrix& diagonalna_k(int k, int* t);
    matrix& kolumna(int x, int* t);
    matrix& wiersz(int y, int* t);
    matrix& przekatna();
    matrix& pod_przekatna();
    matrix& nad_przekatna();
    matrix& szachownica();




};

#endif // MATRIX_H
