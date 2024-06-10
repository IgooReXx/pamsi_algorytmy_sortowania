//
// Created by kubab on 02.05.2024.
//

#ifndef PAMSIPROJ2_READ_H
#define PAMSIPROJ2_READ_H

#include <istream>
#include <vector>
#include "movieEntry.h"
// Funkcja wczytuje dane w formacie CSV (podane w strumieniu `stream`)
// `keyPos` wskazuje na miejsce klucza we wpisie (liczone od 1)
// `nItems` wskazuje ilość wpisów do odczytu
// Dane wczytywane są do wektora `entryList`
//
// W przypadku braku wystarczającej liczby wpisów, aby wypełnić wektor do liczby 'nItems',
// zapętlone zostają wpisy od początku wektora.
//
// Jeżeli we wpisie na miejscu klucza pojawi się znak który nie jest zdefiniowany jako cyfra przez funkcję isdigit(), bądź nie jest kropką
// klucz zostaje zdefiniowany jako nieprawidłowy i wpis jest pominięty.

void read(std::istream& stream, std::vector<movieEntry>& entryList, int keyPos, int nItems);


#endif //PAMSIPROJ2_READ_H
