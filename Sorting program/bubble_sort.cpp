#include <iostream>
#include "sort.h"
#include "functions.h"
#include <vector>


void bubble_sort(vector<int>& numbers, int how_many)
{
    std::cout << "Sorting..." << std::endl;

    int bufor = 0;

    for (int i = 0; i < how_many; i++)
    {
        for (int j = 0; j < how_many - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                bufor = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = bufor;
            }
        }
    }

    std::cout << "Finished sorting" << std::endl;
    write_out(numbers, how_many);
}
