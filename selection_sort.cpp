#include <iostream>
#include "sort.h"
#include "functions.h"


void selection_sort(int numbers[], int how_many)
{
    int bufor = 0;
    int change = 0;

    std::cout << "Sorting..." << std::endl;


    for (int i = 0; i < how_many; i++)
    {

        change = i;

        for (int z = i + 1; z < how_many; z++)
        {
            if (numbers[z] < numbers[change])
            {
                change = z;
            }
        }
        bufor = numbers[change];
        numbers[change] = numbers[i];
        numbers[i] = bufor;
    }

    std::cout << "Finished sorting" << std::endl;
    write_out(numbers, how_many);
}
