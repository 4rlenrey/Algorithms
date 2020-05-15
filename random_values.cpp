#include <iostream>
#include <cstdlib>
#include <ctime>
#include "functions.h"

void random_values(int numbers[], int how_many)
{
   srand (time(NULL));

   for (int i = 0; i < how_many; i++)
             numbers [i] = rand();

std::cout << "Do you want to see those numbes? (Y/N)" << std::endl;

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
