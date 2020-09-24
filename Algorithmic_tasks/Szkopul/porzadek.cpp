/*
Task here:
https://szkopul.edu.pl/c/archiwum-zadan-k0mpend1x/problemset/problem/r2sI-xPUxHi_4OnW7gBWKq6Q/site/?key=statement


*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int rozmiar;
  cin >> rozmiar;
  rozmiar++;

  int suma = 0;

  vector<char> ogrod(rozmiar);
  vector<int> sumy(rozmiar);

  sumy[0] = 0;

  for(int i = 1; i < rozmiar; i++)
  {
    cin >> ogrod[i];

    if (ogrod[i] == 'R')
      suma++;
    sumy[i] = suma;
  }

  int liczba_zapytan;
  cin >> liczba_zapytan;

  int poczatek, koniec;
  long long wynik;

  for(int j = 0; j < liczba_zapytan; j++)
  {
    wynik = 0;
    cin >> poczatek;
    cin >> koniec;
    for(int z = poczatek; z <= koniec; z++)
      {
        if(ogrod[z] == 'N')
          wynik = wynik + (sumy[z] - sumy[poczatek-1]);
      }
      cout << wynik << "\n";
  }

  return 0;
}
