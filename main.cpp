#include <iostream>
#include <chrono>
#include <fstream>
#include <cmath>

#include "read.h"
#include "movieEntry.h"
#include "shuffle.h"
#include "merge_sort.h"
#include "bucket_sort.h"
#include "quick_sort.h"


// https://stackoverflow.com/questions/19555121/how-to-get-current-timestamp-in-milliseconds-since-1970-just-the-way-java-gets

int main(int argc, char* argv[]) {

    int sort_key_pos;
    std::string fileName;
    int n_items;
    std::string algo_name;
    int shuffle_passes = 0;
    std::chrono::milliseconds ms = duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    auto shuffle_seed = ms.count();
    if(argc >= 5)
    {
        fileName = argv[1];
        sort_key_pos = std::stoi(argv[2]) - 1; // odejmujemy 1 (klucz liczony od pierwszej pozycji)
        n_items = std::stoi(argv[3]);
        algo_name = argv[4];
    }
    if(argc >= 6)
    {
        shuffle_passes = std::stoi(argv[5]);
    }
    if(argc == 7)
    {
        shuffle_seed = std::stoi(argv[6]);
    }
    srand(shuffle_seed);

    std::vector<movieEntry> vector;

    std::istream* stream = nullptr;

    if(fileName == "-")
        stream = &std::cin;
    else
        stream = new std::ifstream(fileName);

    read(*stream, vector, sort_key_pos, n_items);

    if(stream != &std::cin)
        delete stream;

    for(int currentPass = 0; currentPass < shuffle_passes; currentPass++)
    {
        shuffle(vector);
    }

    auto start = std::chrono::high_resolution_clock::now();

    if(algo_name == "MERGE")
        merge_sort(vector);
    else if(algo_name == "BUCKET")
        bucket_sort(vector);
    else if(algo_name == "QUICK")
        quick_sort(vector);

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);

    for(int i = 0; i<static_cast<int>( vector.size() ); i++)
    {
        std::cout << vector[i].get_entry() << std::endl;
    }

    std::cerr << shuffle_seed << " ";

    float durationCount = static_cast<float>(duration.count());

    if(duration.count()<1000)
        std::cerr << durationCount << "us";
    else if(duration.count()<1000000)
    {
        durationCount = std::roundf(durationCount)/1000;
        std::cerr << durationCount << "ms";
    }
    else
    {
        durationCount = std::roundf(durationCount/1000)/1000;
        std::cerr << durationCount << "s";
    }
    std::cerr << std::endl;

    return 0;
}
