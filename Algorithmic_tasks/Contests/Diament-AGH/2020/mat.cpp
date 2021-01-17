#include <iostream>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int rozmiar;
  cin >> rozmiar;
  long long l_operac;
  cin >> l_operac;

  int rotato = 0; //always mod of 360
  int all_rotato = 0;
  int r_times = 0;

  char c;
  int arr[rozmiar][rozmiar];

  for (int i = 0; i < rozmiar; i++)
    for (int j = 0; j < rozmiar; j++)
      cin >> arr[i][j];

  int r, u;
  int v;

  while (l_operac)
  {
    cin >> c;
    switch (c)
    {
    case 'A':
      cin >> rotato;
      rotato = rotato % 360;
      all_rotato = all_rotato + rotato;
      break;

    case 'Q':
      cin >> r;
      cin >> u;
      r_times = all_rotato / 90;
      r_times = r_times % 4;
      if (r_times == 0)
        cout << arr[r][u] << "\n";
      else if (r_times == 1)
        cout << arr[rozmiar - 1 - u][r] << "\n";
      else if (r_times == 2)
        cout << arr[rozmiar - 1 - r][rozmiar - 1 - u] << "\n";
      else if (r_times == 3)
        cout << arr[u][rozmiar - 1 - r] << "\n";
      break;

    case 'U':
      cin >> r;
      cin >> u;
      cin >> v;
      arr[r][u] = v;
      break;
    default:
      break;
    }
    l_operac--;
  }
  return 0;
}