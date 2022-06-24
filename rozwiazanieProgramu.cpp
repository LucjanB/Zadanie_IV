//program do obliczania (BIT ERROR RATE)
//Lucjan Bąkowski, grupa D2, numer indeksu 148349.
#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdint.h>
#include <vector>
#include <bitset>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <time.h>
using namespace std;
uint8_t hammingDistance(uint8_t n1, uint8_t n2);
void pliki(const string nazwa, const int licznik, const char wartosc);
void porownaniePlikow(const char* Plik1, const char* Plik2);
void innyPlik(const string nazwa, const int licznik, const char wartosc1, const char wartosc2);
void pliki(const string nazwa, const int licznik, const char wartoscPliku)
{
    ofstream mFile(nazwa);
    for (int i = 0; i < licznik; i++) {
        mFile << wartosc;
    }
}
