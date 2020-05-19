#include <iostream>
#include "functions.h"


using namespace std;

int main(int argc, char const* argv[])
{
    int option;

    cout << "Hello!" << endl;
    cout << "Here is list of available functions:" << endl;
    cout << "Testing specific sorting algorithm (1)." << endl;
    cin >> option;

    switch (option)
    {
        case 1:
            testing();
            break;

        default:
            cout << "Error! Cannot recognize inserted value" << endl;
            break;
    }
    return 0;
}
