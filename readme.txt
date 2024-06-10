Kompilacja programu:
g++ -o prog main.cpp read.cpp movieEntry.cpp get_key.cpp shuffle.cpp merge_sort.cpp bucket_sort.cpp quick_sort.cpp -std=c++20

Wywołanie programu:
prog input_file_name sort_key_pos n_items algo_name shuffle_passes shuffle_seed,
gdzie argumenty to:
input_file_name - nazwa pliku wejściowego ("-" dla standardowego wejścia),
sort_key_pos - numer pozycji klucza (liczony od 1),
n_items - ilość wpisów do odczytu,
algo_name - [MERGE, BUCKET, QUICK],
shuffle_passes - ilość przemieszań listy wpisów (opcjonalny, domyślnie 0),
shuffle_seed - ziarno generatora liczb pseudolosowych (opcjonalny, domyślnie czas uruchomienia programu w milisekundach).

Możliwa kompilacja z użyciem pliku CMakeLists.txt
