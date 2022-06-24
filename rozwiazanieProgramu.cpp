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
uint8_t obliczRoznice(uint8_t n1, uint8_t n2);
void pliki(const string nazwa, const int licznik, const char wartosc);
void porownaniePlikow(const char* Plik1, const char* Plik2);
void innyPlik(const string nazwa, const int licznikStalej, const char wartoscPliku1, const char wartoscPliku2);
void pliki(const string nazwa, const int licznik, const char wartoscPliku)
{
    ofstream mFile(nazwa);
    for (int i = 0; i < licznik; i++) {
        mFile << wartoscPliku;
    }
}
void innyPlik(const string nazwa, const int licznikStalej, const char wartoscPliku1, const char wartoscPliku2)
{
    ofstream mFile(nazwa);
    int i = 0;

    for (i = 0; i < 90; i++) {
        mFile << wartoscPliku1;

    }
    for (i = 90; i < licznikStalej; i++) {
        mFile << wartoscPliku2;

    }
}
uint8_t obliczRoznice(uint8_t n1, uint8_t n2)
{
    uint8_t x = n1 ^ n2; // XOR
    uint8_t setBits = 0;
    while (x > 0)
    {
        setBits += x & 1;
        x >>= 1;
    }
    return setBits;
}
void porownaniePlikow(const char* Plik1, const char* Plik2) {
    ifstream file1(Plik1, ios::binary);
    ifstream file2(Plik2, ios::binary);
    char a{};
    char b{};
    long long int  bity = 0, ber = 0;

    while (!file1.eof())
    {
        file1 >> a;
        file2 >> b;

        if (file1.eof()) { break; }

        bity = bity + 8;
        ber = obliczRoznice(a, b) + ber;

    }
    ofstream log;
    log.open("logi.txt", ios_base::app);
    if (log.good())
    {
        log << "Porownano:" << Plik1 << " i " << Plik2 << endl;
        log << "Bity: " << bity << endl;
        log << "Roznica bitow: : " << ber << endl;
        log << endl;
        log.close();
    }
    cout << "Porownano :" << Plik1 << " i " << Plik2 << endl;
    cout << "Bity: " << bity << endl;
    cout << "Roznica bitow : " << ber << endl;

}
int main(int argc, char* argv[]) {
    cout << "Lucjan Bakowski Grupa D2 - Program liczacy roznice bitow - BER " << endl;
    pliki("plik1.bin", 100, 0x55);
    pliki("plik2.bin", 100, 0x55);
    pliki("plik3.bin", 100, 0x55);
    innyPlik("plik4.bin", 100, 0x55, 0x45);
    pliki("plik5.bin", 400, 0x55);
    pliki("plik6.bin", 400, 0x50);
    cout << "TESTY" << endl;
    cout << "proba 1" << endl;
    porownaniePlikow("plik1.bin", "plik2.bin");
    cout << "proba 2" << endl;
    porownaniePlikow("plik3.bin", "plik4.bin");
    cout << "proba 3" << endl;
    porownaniePlikow("plik5.bin", "plik6.bin");
    cout << "Wynik zapisano w logach, Koniec programu" << endl;
    return 0;
}
