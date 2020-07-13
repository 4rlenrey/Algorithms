/*
Task here:
https://szkopul.edu.pl/problemset/problem/jvPBZm53yfvDkYKuuxbQvjNe/site/?key=statement
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<char> Zagniezdzenie;
    long  stopien = 0;
    long  naj_stopien = 0;
    long long  n; //
    char znak;
    cin >> n;

    if (n%2 != 0)
      {
        cout << "NIE" << "\n";
        return 0;
      }

    for (long long  i = 0; i < n; i++)
    {
        cin >> znak;
        switch (znak)
        {
            case '[':
                Zagniezdzenie.push_back(znak);
                break;

            case ']':
                if (Zagniezdzenie[stopien - 1] == '[')
                {
                    Zagniezdzenie.pop_back();
                }
                else
                {
                    cout << "NIE"
                         << "\n";
                    return 0;
                }
                break;

            case '(':
                Zagniezdzenie.push_back(znak);
                break;

            case ')':
                if (Zagniezdzenie[stopien - 1] == '(')
                {
                    Zagniezdzenie.pop_back();

                }
                else
                {
                    cout << "NIE"
                         << "\n";
                    return 0;
                }
                break;

            case '{':
                Zagniezdzenie.push_back(znak);
                break;

            case '}':
                if (Zagniezdzenie[stopien - 1] == '{')
                {
                    Zagniezdzenie.pop_back();
                }
                else
                {
                    cout << "NIE"
                         << "\n";
                    return 0;
                }
                break;
            default:
                cout << "NIE"
                     << "\n";
                return 0;
        }

        stopien = Zagniezdzenie.size();

        if (stopien > naj_stopien)
            naj_stopien = stopien;

        if (Zagniezdzenie.size() > n-i)
        {
            cout << "NIE"
                 << "\n";
            return 0;
        }


    }

    cout << naj_stopien;

    return 0;
}
