//
// Created by kubab on 06.05.2024.
//

#ifndef PAMSIPROJ2_QUICK_SORT_H
#define PAMSIPROJ2_QUICK_SORT_H

#include <vector>
#include "movieEntry.h"

// https://en.wikipedia.org/wiki/Quicksort

// Funkcja używa Hoare partition scheme.
void quick_sort(std::vector<movieEntry>& entryList);

void q_sort_algorithm(std::vector<movieEntry>& entryList, int low, int high);
int q_sort_partition(std::vector<movieEntry>& entryList, int low, int high);




#endif //PAMSIPROJ2_QUICK_SORT_H
