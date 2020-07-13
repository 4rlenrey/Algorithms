#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Header_files/functions.h"
#include <vector>
using namespace std;


void random_values(vector<int>&numbers, int how_many)
{
    std::cout << "Generating random values..." << std::endl;


    srand(time(NULL));

    for (int i = 0; i < how_many; i++)
        numbers[i] = rand();

    write_out(numbers, how_many);
}
