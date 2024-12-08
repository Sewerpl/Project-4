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






    return o;
}