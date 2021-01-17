#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; //liczba kwiatow
	cin >> n;
	int wynik = 0;
	float suma;
	float srednia;
	vector<float> kwiaty(n);

	for (int i = 0; i < n; i++)
	{
		cin >> kwiaty[i];
	}

	for (int i = 0; i < n; i++)
	{
		suma = 0;
		srednia = 0;

		for (int j = i; j < n; j++)
		{
			suma += kwiaty[j];
			srednia = suma / (j + 1 - i);
			for (int z = i; z <= j; z++)
			{
				if (srednia == kwiaty[z])
				{
					wynik++;
					break;
				}
			}
			srednia = 0;
		}
	}

	cout << wynik << "\n";

	return 0;
}