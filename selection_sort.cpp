#include <iostream>
#include "sort.h"

void selection_sort (int numbers[], int how_many)
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


std::cout << "Do you want to see sorted numbes? (Y/N)" << std::endl;

 char answer;

 std::cin >> answer;

 switch (answer)
 {
   case 'Y':

    for (int i = 0; i < how_many; i++)
        std::cout << numbers[i] << " " << std::endl;

      break;

   default:

   break;
 }
}
