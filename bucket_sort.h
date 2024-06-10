//
// Created by kubab on 06.05.2024.
//

#ifndef PAMSIPROJ2_BUCKET_SORT_H
#define PAMSIPROJ2_BUCKET_SORT_H

#include <vector>
#include "movieEntry.h"

// https://en.wikipedia.org/wiki/Bucket_sort

// Funkcja znajduje najmniejszy (`min`) i największy (`max`) klucz w `entryListy`
bool find_range(int& min, int& max, std::vector<movieEntry>& entryList);
void bucket_sort(std::vector<movieEntry>& entryList);

#endif //PAMSIPROJ2_BUCKET_SORT_H
