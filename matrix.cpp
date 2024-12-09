#include "matrix.h"

/**
 * @brief Zwolnienie pamięci zajmowanej przez macierz.
 * 
 * Funkcja zwalnia pamięć zaalokowaną dynamicznie dla macierzy,
 * a następnie ustawia wskaźnik `data` na `nullptr` oraz rozmiar na 0.
 */
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

/**
 * @brief Alokacja pamięci dla macierzy o zadanym rozmiarze.
 * 
 * Funkcja dynamicznie alokuje pamięć dla macierzy o wymiarach n x n.
 * Wszystkie elementy macierzy są inicjalizowane na 0.
 * 
 * @param n Rozmiar macierzy (n x n).
 */
void matrix::allocateMemory(int n) {
    data = new int*[n];
    for (int i = 0; i < n; ++i) {
        data[i] = new int[n]{0};
    }
    size = n;
}

/**
 * @brief Konstruktor domyślny. Tworzy pustą macierz.
 * 
 * Inicjalizuje wskaźnik `data` na `nullptr` oraz rozmiar na 0.
 */
matrix::matrix() : data(nullptr), size(0) {}

/**
 * @brief Konstruktor tworzący macierz o zadanym rozmiarze.
 * 
 * Dynamicznie alokuje pamięć dla macierzy o wymiarach n x n.
 * 
 * @param n Rozmiar macierzy (n x n).
 */
matrix::matrix(int n) : data(nullptr), size(0) {
    allocateMemory(n);
}

/**
 * @brief Konstruktor tworzący macierz i wypełniający ją danymi z tablicy.
 * 
 * Dynamicznie alokuje pamięć dla macierzy o wymiarach n x n,
 * a następnie wypełnia ją danymi z podanej tablicy `t`.
 * 
 * @param n Rozmiar macierzy (n x n).
 * @param t Wskaźnik do jednowymiarowej tablicy zawierającej dane do wpisania.
 */
matrix::matrix(int n, int* t) : data(nullptr), size(0) {
    allocateMemory(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = t[i * n + j];
        }
    }
}

/**
 * @brief Konstruktor kopiujący.
 * 
 * Tworzy nową macierz będącą kopią podanej macierzy `m`.
 * 
 * @param m Macierz, którą należy skopiować.
 */
matrix::matrix(const matrix& m) : data(nullptr), size(0) {
    allocateMemory(m.size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = m.data[i][j];
        }
    }
}

/**
 * @brief Destruktor.
 * 
 * Zwalnia pamięć zaalokowaną przez macierz.
 */
matrix::~matrix() {
    freeMemory();
}

/**
 * @brief Alokacja pamięci dla macierzy o zadanym rozmiarze.
 * 
 * Jeśli rozmiar jest różny od obecnego rozmiaru macierzy, pamięć zostaje
 * zwolniona i zaalokowana ponownie. Jeśli rozmiar jest taki sam, nic się nie dzieje.
 * 
 * @param n Nowy rozmiar macierzy (n x n).
 * @return Referencja do obiektu klasy `matrix`.
 */
matrix& matrix::alokuj(int n) {
    if (size != n) {
        freeMemory();
        allocateMemory(n);
    }
    return *this;
}

/**
 * @brief Wstawia wartość do macierzy w określonej pozycji.
 * 
 * @param x Indeks wiersza.
 * @param y Indeks kolumny.
 * @param wartosc Wartość do wstawienia.
 * @return Referencja do obiektu klasy `matrix`.
 */
matrix& matrix::wstaw(int x, int y, int wartosc) {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        data[x][y] = wartosc;
    }
    return *this;
}

/**
 * @brief Zwraca wartość elementu macierzy z określonej pozycji.
 * 
 * @param x Indeks wiersza.
 * @param y Indeks kolumny.
 * @return Wartość elementu macierzy lub 0, jeśli indeksy są nieprawidłowe.
 */
int matrix::pokaz(int x, int y) const {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        return data[x][y];
    }
    return 0;
}

/**
 * @brief Transponuje macierz (zamienia wiersze z kolumnami).
 * 
 * Tworzy tymczasową macierz, przepisuje dane w transponowany sposób,
 * a następnie podmienia oryginalną macierz na transponowaną.
 * 
 * @return Referencja do obiektu klasy `matrix`.
 */
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

/**
 * @brief Wypełnia macierz losowymi liczbami od 0 do 9.
 * 
 * Losowane wartości są umieszczane we wszystkich elementach macierzy.
 * 
 * @return Referencja do obiektu klasy `matrix`.
 */
matrix& matrix::losuj() {
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = rand() % 10;
        }
    }
    return *this;
}

/**
 * @brief Wypisuje macierz na standardowe wyjście.
 * 
 * Elementy macierzy są formatowane w czytelnej formie.
 * 
 * @param o Strumień wyjściowy.
 * @param m Obiekt macierzy do wypisania.
 * @return Referencja do strumienia wyjściowego.
 */
std::ostream& operator<<(std::ostream& o, const matrix& m) {
    for (int i = 0; i < m.size; ++i) {
        for (int j = 0; j < m.size; ++j) {
            o << std::setw(4) << m.data[i][j];
        }
        o << '\n';
    }
    return o;
}
