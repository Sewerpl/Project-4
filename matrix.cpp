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







    return o;
}