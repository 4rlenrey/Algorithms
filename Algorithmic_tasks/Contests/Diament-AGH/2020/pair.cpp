#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int rozmiar;
    cin >> rozmiar;
    int zakres;
    cin >> zakres;
    int wynik = 0;
    int j;
    vector<long> a(rozmiar);

    for (int i = 0; i < rozmiar; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    if (a[0] + zakres >= a[1])
    {
        if(a[0] != a[1])
            wynik++;
          else
        {
            j = 0;
            while (a[j] == a[j + 1] && j < rozmiar - 1)
            {
                j++;
            }
            if (a[0] <= a[j + 1] + zakres )
                wynik++;
        }
    }

    for (int i = 1; i < rozmiar - 1; i++)
    {
        if (a[i] + zakres >= a[i + 1] && a[i] != a[i + 1])
        {
            wynik++;
        }
        else if (a[i] <= a[i - 1] + zakres && a[i] != a[i - 1])
            wynik++;
        else
        {
            if (a[i] == a[i + 1])
            {
                j = i;
                while (a[j] == a[j + 1] && j < zakres - 1)
                    j++;
                if (a[j] + zakres > a[j + 1] && a[j] != a[j + 1])
                {
                    wynik++;
                }
            }
            else if (a[i] == a[i - 1])
            {
                j = i;
                while (a[j] == a[j - 1] && j > 0)
                {
                    j--;
                }
                if (a[i] < a[j - 1] + zakres && a[i] != a[j - 1])
                    wynik++;
            }
        }
    }
    if (a[rozmiar - 1] <= a[rozmiar - 2] + zakres)
    {
        if (a[rozmiar - 1] != a[rozmiar - 2])
            wynik++;
        else
        {
            j = rozmiar - 1;
            while (a[j] == a[j - 1] && j > 0)
            {
                j--;
            }
            if (a[rozmiar - 1] <= a[j - 1] + zakres )
                wynik++;
        }
    }

    cout << wynik << "\n";
}