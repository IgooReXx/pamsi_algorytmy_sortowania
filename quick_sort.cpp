//
// Created by kubab on 06.05.2024.
//

#include "quick_sort.h"


void quick_sort(std::vector<movieEntry>& entryList)
{
    if(entryList.empty()) return;
    q_sort_algorithm(entryList, 0, entryList.size()-1);
}

void q_sort_algorithm(std::vector<movieEntry>& entryList, int low, int high)
{
    if(low >= 0 and high >= 0 and low < high)
    {
        int pivot = q_sort_partition(entryList, low, high);
        q_sort_algorithm(entryList, low, pivot);
        q_sort_algorithm(entryList, pivot+1, high);
    }
}

int q_sort_partition(std::vector<movieEntry>& entryList, int low, int high)
{
    int pivot = entryList[low].get_rating();

    int leftIndex = low-1;
    int rightIndex = high+1;

    while(true)
    {
        do
            leftIndex = leftIndex + 1;
        while (entryList[leftIndex].get_rating() < pivot);

        do
            rightIndex = rightIndex - 1;
        while (entryList[rightIndex].get_rating() > pivot);

        if (leftIndex >= rightIndex)
            return rightIndex;


        std::swap(entryList[leftIndex], entryList[rightIndex]);
    }
}