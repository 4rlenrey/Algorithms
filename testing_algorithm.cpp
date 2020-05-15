#include <iostream>
#include "functions.h"
#include "sort.h"

void testing()
{
    int how_many;
    char algorithm;
    char answer;

    std::cout << "witch algorithm do you want to test?" << std::endl;
    std::cout << "bubble sort (B)" << std::endl;
    std::cout << "selection sort (S)" << std::endl;

    std::cin >> algorithm;

    std::cout << "Do you want to sort your own values?(Y/N)" << std::endl;

    std::cin >> answer;

    std::cout << "how many values do you want to sort?" << std::endl;

    std::cin >> how_many;

    int numbers[how_many];


    switch (answer)
    {
        case 'Y':
            std::cout << "Insert your numbers to sort" << std::endl;
            for (int i = 0; i < 10; i++)
                std::cin >> numbers[i];
            break;

        case 'N':
            random_values(numbers, how_many);
            break;

        default:
            std::cout << "Error! Cannot recognize inserted value" << std::endl;
            break;
    }


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
