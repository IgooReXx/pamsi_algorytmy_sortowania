//
// Created by kubab on 02.05.2024.
//

#include "read.h"
#include <fstream>
#include "get_key.h"
#include <cctype>
#include "iostream"

void read(std::istream& stream, std::vector<movieEntry>& entryList, int keyPos, int nItems)
{
    bool validRating = false;
    int linesRead = 0, bufferCharAmount = 0, loopedEntries = 0;
    std::string lineBuffer, keyBuffer;
    while(std::getline(stream, lineBuffer))
    {
        if(linesRead == nItems)
            break;
        bufferCharAmount = 0;
        validRating = false;
        keyBuffer = get_key(lineBuffer, keyPos);
        if(keyBuffer.empty())
            continue;
        for (int keyIndex = 0; keyIndex < static_cast<int>(keyBuffer.length()); ++keyIndex)
        {
            if(isdigit(keyBuffer[keyIndex]))
                bufferCharAmount++;
            else if(keyBuffer[keyIndex] == '.')
                bufferCharAmount++;
        }
        if(bufferCharAmount == static_cast<int>(keyBuffer.length()))
            validRating = true;
        if(validRating and keyBuffer.length() > 0)
        {
            if(isdigit(keyBuffer[0]))
            {
                entryList.emplace_back(lineBuffer, keyPos);
                linesRead++;
            }
        }
    }

    if(linesRead == 0)
        return;

    while(linesRead < nItems)
    {
        entryList.emplace_back(entryList[loopedEntries]);
        loopedEntries++;
        linesRead++;
    }
}
