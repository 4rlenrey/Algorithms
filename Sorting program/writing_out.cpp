#include <iostream>
#include "functions.h"

void write_out(int numbers[], int how_many)
{
    std::cout << "Do you want to see those numbes? (Y/N)" << std::endl;

    char answer;

    std::cin >> answer;

    switch (answer)
    {
        case 'Y':
            for (int i = 0; i < how_many; i++)
                std::cout << numbers[i] << " " << std::endl;
            break;

        case 'N':
            std::cout << "Ok" << std::endl;

        default:
            std::cout << "Error! Cannot recognize inserted value" << std::endl;
            break;
    }
}
