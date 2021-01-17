#include <iostream>

using namespace std;

int fibonacci_sequence(int number)
{
    int x = 0;
    int y = 1;
    int c = 0;
    for(int i = 1; i < number; i++)
    {
        c = x + y;
        x = y;
        y = c;
    }
    return c;
}


int fibonacci_sequence_rec(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    else 
        return fibonacci_sequence(n-1) + fibonacci_sequence(n-2);
}


int main()
{
    int n = 4;
    cout <<  fibonacci_sequence_rec(n) << "\n";
    cout <<  fibonacci_sequence(n) << "\n";
}