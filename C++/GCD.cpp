#include <iostream> 

using namespace std;

int greatest_common_divider(int a, int b)
{
    while(a != b)
    {
        if (a > b)
            a = a - b;
        else 
            b = b - a;
    }
    return a;
}

int main()
{
    int a = 20;
    int b = 50;
    cout << greatest_common_divider(a, b) << "\n";
}