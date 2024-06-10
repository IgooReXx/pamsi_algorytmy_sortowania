//
// Created by kubab on 02.05.2024.
//

#ifndef PAMSIPROJ2_MOVIEENTRY_H
#define PAMSIPROJ2_MOVIEENTRY_H

#include <string>
#include <compare>

// https://en.cppreference.com/w/cpp/utility/compare/strong_ordering

// Klasa przechowująca wpis oraz rating (klucz).

class movieEntry {
    std::string entry;
    int rating;

public:

    movieEntry(std::string e, int keyPos);
    std::strong_ordering operator<=>(const movieEntry& other);
    bool operator==(const movieEntry& other);
    std::string get_entry();
    int get_rating();

};


#endif //PAMSIPROJ2_MOVIEENTRY_H
