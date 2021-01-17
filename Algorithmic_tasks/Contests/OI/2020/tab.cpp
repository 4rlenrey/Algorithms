#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pair<int, int> rozmiar;
	int l;
	cin >> rozmiar.first;
	cin >> rozmiar.second;
	cin >> l; //liczba operacji

	int oy;
	int ox;
	int ay;
	int ax;

	if (l == 1) //gotowe 2
	{
		cin >> ox;
		cin >> oy;
		cin >> ax;
		cin >> ay;
		if ((ox == 1 && oy == 1) || (ax == 1 && ay == 1))
		{
			cout << 1 << "\n";
		}
		else if ((ox == 1 || oy == 1) || (ax == 1 || ay == 1))
		{
			cout << 2 << "\n";
		}
		else
			cout << 4 << "\n";
	}
	else if (rozmiar.first == 2 && rozmiar.second == 2)
	{
		int tab[3][3] = {0}; //yx
		for (int i = 0; i < l; i++)
		{
			int ruchy = 0;
			cin >> ox;
			cin >> oy;
			cin >> ax;
			cin >> ay;
			if (oy == ay && ox == ax) //1x1
			{
				if (tab[oy][ox] == 0)
					tab[oy][ox] = 1;
				else
					tab[oy][ox] = 0;
			}

			else if (((oy == 1 && ox == 1) && (ay == 2 && ax == 2)) || ((oy == 1 && ox == 1) && (ay == 2 && ax == 2))) // 2 x 2
			{
				if (tab[1][1] == 0)
					tab[1][1] = 1;
				else
					tab[1][1] = 0;

				if (tab[1][2] == 0)
					tab[1][2] = 1;
				else
					tab[1][2] = 0;

				if (tab[2][1] == 0)
					tab[2][1] = 1;
				else
					tab[2][1] = 0;

				if (tab[2][2] == 0)
					tab[2][2] = 1;
				else
					tab[2][2] = 0;
			}

			else // 1 x 2
			{
				if (tab[oy][ox] == 0)
					tab[oy][ox] = 1;
				else
					tab[oy][ox] = 0;

				if (tab[ay][ax] == 0)
					tab[ay][ax] = 1;
				else
					tab[ay][ax] = 0;
			}

			if (tab[1][1] == 0 && tab[1][2] == 0 && tab[2][1] == 0 && tab[2][2] == 0) //2x2
			{
				cout << 0 << "\n";
			}
			else
			{
				if (tab[1][1] == 1 && tab[1][2] == 1 && tab[2][1] == 1 && tab[2][2] == 1) //2x2
					cout << 1 << "\n";
				else if (tab[1][1] == 1 && tab[1][2] == 0 && tab[2][1] == 0 && tab[2][2] == 1) //skos
					cout << 3 << "\n";
				else if (tab[1][1] == 0 && tab[1][2] == 1 && tab[2][1] == 1 && tab[2][2] == 0) //skos
					cout << 2 << "\n";
				else if (tab[1][1] == 1 && tab[1][2] == 0 && tab[2][1] == 1 && tab[2][2] == 0) //dol
					cout << 1 << "\n";
				else if (tab[1][1] == 1 && tab[1][2] == 1 && tab[2][1] == 0 && tab[2][2] == 0) //gora
					cout << 2 << "\n";
				else if (tab[1][1] == 0 && tab[1][2] == 0 && tab[2][1] == 1 && tab[2][2] == 1) //bok
					cout << 2 << "\n";
				else if (tab[1][1] == 0 && tab[1][2] == 1 && tab[2][1] == 0 && tab[2][2] == 1) //bok
					cout << 2 << "\n";
				else if (tab[1][1] == 1 && tab[1][2] == 0 && tab[2][1] == 0 && tab[2][2] == 0)
					cout << 1 << "\n";
				else if (tab[1][1] == 0 && tab[1][2] == 1 && tab[2][1] == 0 && tab[2][2] == 0)
					cout << 2 << "\n";
				else if (tab[1][1] == 0 && tab[1][2] == 0 && tab[2][1] == 1 && tab[2][2] == 0)
					cout << 2 << "\n";
				else if (tab[1][1] == 0 && tab[1][2] == 0 && tab[2][1] == 0 && tab[2][2] == 1)
					cout << 4 << "\n";
				else if (tab[1][1] == 1 && tab[1][2] == 1 && tab[2][1] == 0 && tab[2][2] == 1)
					cout << 3 << "\n";
				else if (tab[1][1] == 1 && tab[1][2] == 1 && tab[2][1] == 1 && tab[2][2] == 0)
					cout << 3 << "\n";
				else if (tab[1][1] == 1 && tab[1][2] == 0 && tab[2][1] == 1 && tab[2][2] == 1)
					cout << 3 << "\n";
				else if (tab[1][1] == 0 && tab[1][2] == 1 && tab[2][1] == 1 && tab[2][2] == 1)
					cout << 2 << "\n";
			}
		}
	}
	else if (rozmiar.second > 1 && rozmiar.first == 1) //gotowe
	{
		int tab[rozmiar.second + 1] = {0}; //yx
		for (int i = 0; i < l; i++)
		{
			int ruchy = 0;
			int ll = 1;
			cin >> ox;
			cin >> oy;
			cin >> ax;
			cin >> ay;
			for (int j = oy; j <= ay; j++)
				if (tab[j] == 0)
					tab[j] = 1;
				else
					tab[j] = 0;

			if (tab[ll] == 1)
			{
				ruchy++;
				while (tab[ll] == 0 && ll <= rozmiar.second)
				{
					ll++;
				}
				while (tab[ll] == 1 && ll <= rozmiar.second)
				{
					ll++;
				}
			}
			bool bylo = false;
			while (ll <= rozmiar.second)
			{
				while (tab[ll] == 0 && ll <= rozmiar.second)
				{
					ll++;
				}
				while (tab[ll] == 1 && ll <= rozmiar.second)
				{
					ll++;
					bylo = true;
				}
				if (bylo)
					ruchy += 2;
				bylo = false;
			}
			cout << ruchy << "\n";
		}
	}

	return 0;
}