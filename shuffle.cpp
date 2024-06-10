//
// Created by kubab on 05.05.2024.
//

#include "shuffle.h"


void shuffle(std::vector<movieEntry>& entryList)
{
    int size = static_cast<int>(entryList.size());
    for(int listIterator=0; listIterator < size; listIterator++)
    {
        int rand_indx = static_cast<int>(rand()%size);
        std::swap(entryList[listIterator], entryList[rand_indx]);
    }
}