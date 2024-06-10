//
// Created by kubab on 06.05.2024.
//

#include "merge_sort.h"


void merge_sort(std::vector<movieEntry>& entryList)
{
    if(entryList.empty()) return;
    std::vector<movieEntry> temp;
    td_merge_sort(entryList, temp, entryList.size());
}

void td_merge_sort(std::vector<movieEntry>& entryList, std::vector<movieEntry>& temp, int entryNumber)
{
    copy_vector(entryList, temp);
    td_split_merge(entryList, 0, entryNumber, temp);
}

void copy_vector(std::vector<movieEntry>& entryList, std::vector<movieEntry>& temp)
{
    temp = entryList;
}

void td_split_merge(std::vector<movieEntry>& temp, int listBegin, int listEnd, std::vector<movieEntry>& entryList)
{
    if(listEnd-listBegin <= 1)
    {
        return;
    }
    int listMiddle = (listEnd + listBegin) / 2;
    td_split_merge(entryList, listBegin, listMiddle, temp);
    td_split_merge(entryList, listMiddle, listEnd, temp);
    td_merge(temp, listBegin, listMiddle, listEnd, entryList);
}

void td_merge(std::vector<movieEntry>& temp, int listBegin, int listMiddle, int listEnd, std::vector<movieEntry>& entryList)
{
    int leftIterator = listBegin, rightIterator = listMiddle;
    for(int elementsSorted = listBegin; elementsSorted<listEnd; elementsSorted++)
    {
        if(leftIterator < listMiddle and (rightIterator>= listEnd or entryList[leftIterator].get_rating() <= entryList[rightIterator].get_rating()))
        {
            temp[elementsSorted] = entryList[leftIterator];
            leftIterator = leftIterator + 1;
        }
        else
        {
            temp[elementsSorted] = entryList[rightIterator];
            rightIterator = rightIterator + 1;
        }
    }
}

