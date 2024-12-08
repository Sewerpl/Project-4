#include "matrix.h"

// Metoda pomocnicza do zwalniania pamięci
void matrix::freeMemory() {
    if (data) {
        for (int i = 0; i < size; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
    data = nullptr;
    size = 0;
}

// Metoda pomocnicza do alokacji pamięci
void matrix::allocateMemory(int n) {
    data = new int*[n];
    for (int i = 0; i < n; ++i) {
        data[i] = new int[n]{0};
    }
    size = n;
}

// Konstruktor domyślny
matrix::matrix() : data(nullptr), size(0) {}

// Konstruktor z rozmiarem
matrix::matrix(int n) : data(nullptr), size(0) {
    allocateMemory(n);
}

// Konstruktor z tablicą
matrix::matrix(int n, int* t) : data(nullptr), size(0) {
    allocateMemory(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = t[i * n + j];
        }
    }
}



// Konstruktor kopiujący
matrix::matrix(const matrix& m) : data(nullptr), size(0) {
    allocateMemory(m.size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = m.data[i][j];
        }
    }
}


// Destruktor
matrix::~matrix() {
    freeMemory();
}


// Alokacja pamięci
matrix& matrix::alokuj(int n) {
    if (size != n) {
        freeMemory();
        allocateMemory(n);
    }
    return *this;
}

// Wstawianie wartości
matrix& matrix::wstaw(int x, int y, int wartosc) {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        data[x][y] = wartosc;
    }
    return *this;
}


// Pokazywanie wartości
int matrix::pokaz(int x, int y) const {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        return data[x][y];
    }
    return 0;
}


// Obracanie macierzy
matrix& matrix::dowroc() {
    matrix temp(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            temp.data[j][i] = data[i][j];
        }
    }
    *this = temp;
    return *this;
}






    return o;
}