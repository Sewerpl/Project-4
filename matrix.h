#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

/**
 * @class matrix
 * @brief Klasa reprezentująca macierz kwadratową.
 * 
 * Klasa umożliwia zarządzanie dynamiczną macierzą kwadratową oraz wykonanie na niej operacji arytmetycznych,
 * modyfikacji, losowego wypełnienia i innych działań.
 */
class matrix {
private:
    int** data;  ///< Wskaźnik do dynamicznej tablicy przechowującej elementy macierzy.
    int size;    ///< Rozmiar macierzy (liczba wierszy/kolumn).

    /**
     * @brief Zwolnienie pamięci zajmowanej przez macierz.
     */
    void freeMemory();

    /**
     * @brief Alokacja pamięci dla macierzy o zadanym rozmiarze.
     * 
     * @param n Rozmiar macierzy.
     */
    void allocateMemory(int n);

public:
    /**
     * @brief Konstruktor domyślny. Tworzy pustą macierz.
     */
    matrix();

    /**
     * @brief Konstruktor tworzący macierz o zadanym rozmiarze.
     * 
     * @param n Rozmiar macierzy.
     */
    matrix(int n);

    /**
     * @brief Konstruktor tworzący macierz i wypełniający ją danymi z tablicy
     * 
     * @param n Rozmiar macierzy.
     * @param t Tablica jednowymiarowa z danymi do wpisania.
     */
    matrix(int n, int* t);

    /**
     * @brief Konstruktor kopiujący.
     * 
     * @param m Macierz do skopiowania.
     */
    matrix(const matrix& m);

    /**
     * @brief Destruktor. Zwalnia pamięć zajmowaną przez macierz.
     */
    ~matrix();

    /**
     * @brief Alokacja pamięci dla macierzy o zadanym rozmiarze.
     * 
     * @param n Rozmiar macierzy.
     * @return Referencja do obiektu klasy matrix.
     */
    matrix& alokuj(int n);

    /**
     * @brief Wstawia wartość do macierzy.
     * 
     * @param x Indeks wiersza.
     * @param y Indeks kolumny.
     * @param wartosc Wartość do wstawienia.
     * @return Referencja do obiektu klasy matrix.
     */
    matrix& wstaw(int x, int y, int wartosc);

    /**
     * @brief Zwraca wartość z macierzy.
     * 
     * @param x Indeks wiersza.
     * @param y Indeks kolumny.
     * @return Wartość elementu macierzy.
     */
    int pokaz(int x, int y) const;

    /**
     * @brief Transponuje macierz (zamienia wiersze z kolumnami).
     * 
     * @return Referencja do obiektu klasy matrix.
     */
    matrix& dowroc();

    /**
     * @brief Wypełnia macierz losowymi liczbami od 0 do 9.
     * 
     * @return Referencja do obiektu klasy matrix.
     */
    matrix& losuj();

    /**
     * @brief Operator wypisywania macierzy na standardowe wyjście.
     * 
     * @param o Strumień wyjściowy.
     * @param m Obiekt macierzy do wypisania.
     * @return Referencja do strumienia wyjściowego.
     */
    friend std::ostream& operator<<(std::ostream& o, const matrix& m);
};

#endif // MATRIX_H
