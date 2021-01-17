#include <iostream>
#include <queue>

using namespace std;


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long dlugosc;
    int l_operacji;
    int suma = 0;
    cin >> dlugosc;
    cin >> l_operacji;

    std::priority_queue<long long> kol;

    long long x;

    for(int i = 0; i < dlugosc; i++)
    {
        cin >> x;
        kol.push(x);
    }

    while (l_operacji)
    {
        kol.push(kol.top()/2);
        kol.pop();
        l_operacji--;
    }
    
    while (kol.empty() == false)
    {
        suma = suma + kol.top();
        kol.pop();
    }
    
    cout << suma << "\n";

}