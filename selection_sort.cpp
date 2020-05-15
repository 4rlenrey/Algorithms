#include <iostream>
#include "sort.h"
#include "functions.h"


void selection_sort(int numbers[], int how_many)
{
    int bufor = 0;
    int change = 0;


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
    write_out( numbers, how_many);

}
