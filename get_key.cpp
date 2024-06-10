//
// Created by kubab on 03.05.2024.
//

#include "get_key.h"
#include "iostream"
std::string get_key(std::string entry, int keyPos)
{
    int circumflexCounter = 0, entryIterator = 0;
    std::string keyBuffer;
    while(circumflexCounter<keyPos)
    {
    if(entry[entryIterator] == '^')
        circumflexCounter++;
    entryIterator++;
    }
    while(entryIterator < static_cast<int>(entry.length()) and entry[entryIterator] != '^' and circumflexCounter == keyPos)
    {
        keyBuffer.push_back(entry[entryIterator]);
        entryIterator++;
    }

    return keyBuffer;
}