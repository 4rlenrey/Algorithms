#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int p; //liczba platform
	int d; //dlugosc platform
	int z; //liczba zapytan

	cin >> p;
	cin >> d;
	cin >> z;

	int x;
	int y;
	vector<pair<pair<int, int>, int>> dziury; //pozycja poziom ilejestdokonca

	int l_dziur[p + 1];

	for (int i = 1; i <= p; i++)
	{
		cin >> l_dziur[i];
		for (int j = 0; j < l_dziur[i]; j++)
		{
			cin >> y;
			dziury.push_back(make_pair(make_pair(y, i), 0));
		}
	}

	sort(dziury.begin(), dziury.end());

	int dzp = dziury.size();

	int t; //chinese iterator is back
	int l; //japanese iterator is back
	int h; //korean iterator is back

	bool wyzej = false;
	bool nizej = false;
	bool przed = false;

	dzp--;

	while (dzp + 1)
	{
		if (dziury[dzp].first.second == p) // dla najnizszego
		{
			for (t = dzp + 1; t <= dziury.size(); t++)
			{
				if (dziury[t].first.second == p)
				{
					przed = true;
					break;
				}
				else if (dziury[t].first.second == p - 1 && !wyzej)
				{
					l = t;
					wyzej = true;
				}
			}
			if (przed && wyzej)
			{
				if (dziury[t].second < dziury[l].second)
				{
					dziury[dzp].second = dziury[t].second + 1;
				}
				else
				{
					dziury[dzp].second = dziury[l].second + 1;
				}
			}
			else if (przed)
			{
				dziury[dzp].second = dziury[t].second + 1;
			}
			else
			{
				dziury[dzp].second = 1;
			}
			przed = false;
			nizej = false;
			wyzej = false;
		}
		else
		{
			for (t = dzp + 1; t <= dziury.size(); t++)
			{
				if (dziury[t].first.second == dziury[dzp].first.second)
				{
					przed = true;
					break;
				}
				else
				{
					if (dziury[t].first.second == dziury[dzp].first.second + 1 && !nizej)
					{
						l = t;
						nizej = true;
					}
					if (dziury[t].first.second == dziury[dzp].first.second - 1 && !wyzej)
					{
						h = t;
						wyzej = true;
					}
				}
			}

			if (przed && !nizej)
			{
				dziury[dzp].second = dziury[t].second;
			}
			else if (przed && nizej && !wyzej)
			{
				if (dziury[t].second + 1 <= dziury[l].second)
					dziury[dzp].second = dziury[t].second + 1;
				else
					dziury[dzp].second = dziury[l].second;
			}
			else if (przed && nizej && wyzej)
			{
				if (dziury[t].second + 1 <= dziury[l].second && dziury[t].second <= dziury[h].second)
					dziury[dzp].second = dziury[t].second + 1;
				else if (dziury[h].second + 1 <= dziury[l].second)
					dziury[dzp].second = dziury[h].second + 1;
				else
					dziury[dzp].second = dziury[l].second;
			}
			else if (!przed && nizej && wyzej)
			{
				if (dziury[h].second + 1 <= dziury[l].second)
					dziury[dzp].second = dziury[h].second + 1;
				else
					dziury[dzp].second = dziury[l].second;
			}
			else if (!przed && nizej)
			{
				if (dziury[l].second < 2)
					dziury[dzp].second = dziury[l].second;
				else
				{
					dziury[dzp].second = 1;
				}
			}
			else if (!przed)
				dziury[dzp].second = 0;

			przed = false;
			nizej = false;
			wyzej = false;
		}

		dzp--;
	}

	przed = false;
	nizej = false;
	wyzej = false;
	int liczba_zapytan = p;
	int zapytanie = 0;
	int wyjscia[p + 1];

	while (liczba_zapytan)
	{
		zapytanie++;

		if (l_dziur[zapytanie] == 0)
			wyjscia[zapytanie] = 0;
		else
		{
			for (t = 0; t <= dziury.size(); t++)
			{
				if (dziury[t].first.second == zapytanie)
				{
					przed = true;
					break;
				}
				else if (dziury[t].first.second == zapytanie - 1 && !wyzej)
				{
					h = t;
					wyzej = true;
				}
			}
			if (zapytanie == p) //pozycja poziom ilejestdokonca
			{
				if (przed && wyzej)
				{
					if (dziury[t].second <= dziury[h].second)
						wyjscia[zapytanie] = dziury[t].second;
					else
						wyjscia[zapytanie] = dziury[h].second;
				}
				else
				{
					wyjscia[zapytanie] = dziury[t].second;
				}
			}
			else
			{

				if (!wyzej)
					wyjscia[zapytanie] = dziury[t].second;
				else
				{
					if (dziury[h].second <= dziury[t].second)
						wyjscia[zapytanie] = dziury[h].second;
					else
						wyjscia[zapytanie] = dziury[t].second;
				}
			}
		}
		liczba_zapytan--;
		przed = false;
		wyzej = false;
	}

	liczba_zapytan = z;

	while (liczba_zapytan)
	{
		cin >> zapytanie;
		cout << wyjscia[zapytanie] << "\n";
		liczba_zapytan--;
	}

	return 0;
}