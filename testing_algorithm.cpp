#include <iostream>
#include "functions.h"
#include "sort.h"

void testing()
{
   int how_many;
   char algorithm;

std::cout << "witch algorithm do you want to test?" << std::endl;
std::cout << "bubble sort (B)" << std::endl;
std::cout << "selection sort (S)" << std::endl;

std::cin >> algorithm;

std::cout << "how many values do you want to sort?" << std::endl;

std::cin >> how_many;

  int numbers[how_many];

random_values(numbers, how_many);


switch (algorithm)
{
  case 'B':
  bubble_sort(numbers, how_many);
  break;

  case 'S':
  selection_sort(numbers, how_many);
  break;

  default:
  std::cout << "Error! Cannot recognize inserted value" << std::endl;
  break;

}

}
