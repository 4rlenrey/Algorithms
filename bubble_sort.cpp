#include <iostream>
#include "sort.h"

void bubble_sort (int numbers[], int how_many)
{
    int bufor = 0;

 for (int i = 0; i < how_many; i++)
{
   for( int j = 0; j < how_many - 1; j++ )
  {
     if( numbers[ j ] > numbers[ j + 1 ] )
   {
    bufor = numbers[j];
    numbers[j] = numbers[j+1];
    numbers[j+1] = bufor;
   }
  }
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
