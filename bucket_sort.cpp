//
// Created by kubab on 06.05.2024.
//

#include "bucket_sort.h"

bool find_range(int& min, int& max, std::vector<movieEntry>& entryList)
{
    if(entryList.empty())
    {
        return false;
    }
    min = entryList[0].get_rating();
    max = entryList[0].get_rating();
    for(int listIterator = 0; listIterator < static_cast<int>(entryList.size()); listIterator++)
    {
        if(entryList[listIterator].get_rating() < min)
            min = entryList[listIterator].get_rating();
        if(entryList[listIterator].get_rating() > max)
            max = entryList[listIterator].get_rating();
    }
    return true;
}

void bucket_sort(std::vector<movieEntry>& entryList)
{
    if(entryList.empty()) return;
    int min, max;
    find_range(min, max, entryList);
    int bucketAmount = max - min;
    std::vector<movieEntry>* bucket = new std::vector<movieEntry>[bucketAmount+1];

    for(int listIterator = 0; listIterator < static_cast<int>(entryList.size()); listIterator++)
    {
        int bucketIndex = max - entryList[listIterator].get_rating();
        bucket[bucketIndex].push_back(entryList[listIterator]);
    }
    int listIterator = 0;
    for(int bucketsIterator = bucketAmount; bucketsIterator >= 0; bucketsIterator--)
    {
        for(int copiedElements = 0; copiedElements < static_cast<int>(bucket[bucketsIterator].size()); copiedElements++)
        {
            entryList[listIterator] = bucket[bucketsIterator][copiedElements];
            listIterator++;
        }
    }

    delete[] bucket;
}