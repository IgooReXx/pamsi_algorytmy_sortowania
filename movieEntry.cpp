//
// Created by kubab on 02.05.2024.
//

#include "movieEntry.h"
#include "get_key.h"
#include "iostream"

movieEntry::movieEntry(std::string e, int keyPos) : entry(e)
{
    rating = std::stoi(get_key(entry, keyPos));
}

std::strong_ordering movieEntry::operator<=>(const movieEntry& other)
{
    return rating <=> other.rating;
}

bool movieEntry::operator==(const movieEntry& other)
{
    return this->rating == other.rating;
}

std::string movieEntry::get_entry()
{
    return entry;
}

int movieEntry::get_rating()
{
    return rating;
}