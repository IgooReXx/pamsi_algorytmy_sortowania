//
// Created by kubab on 06.05.2024.
//

#ifndef PAMSIPROJ2_MERGE_SORT_H
#define PAMSIPROJ2_MERGE_SORT_H

#include <vector>
#include "movieEntry.h"

// https://en.wikipedia.org/wiki/Merge_sort

void merge_sort(std::vector<movieEntry>& entryList);

void td_merge_sort(std::vector<movieEntry>& entryList, std::vector<movieEntry>& temp, int entryNumber);
void td_split_merge(std::vector<movieEntry>& temp, int listBegin, int listEnd, std::vector<movieEntry>& entryList);
void td_merge(std::vector<movieEntry>& temp, int listBegin, int listMiddle, int listEnd, std::vector<movieEntry>& entryList);
void copy_vector(std::vector<movieEntry>& entryList, std::vector<movieEntry>& temp);

#endif //PAMSIPROJ2_MERGE_SORT_H
