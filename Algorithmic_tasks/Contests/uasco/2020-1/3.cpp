#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int liczba;
	cin >> liczba;
	int wynik;
	vector<pair<pair<int, int>, char>> krowy;
	vector<pair<int, int>> krowye;
	vector<pair<int, int>> krowyn;
	char c;
	int x;
	int y;
	bool iff = false;

	for (int i = 0; i < liczba; i++)
	{
		cin >> c;
		cin >> x;
		cin >> y;
		krowy.push_back(make_pair(make_pair(x, y), c));
		if (c == 'N')
			krowyn.push_back(make_pair(x, y));
		else
			krowye.push_back(make_pair(y, x));
	}

	sort(krowyn.begin(), krowyn.end());
	sort(krowye.begin(), krowye.end());

	int odx;
	int ody;
	int oo, oox;

	for (int i = 0; i < liczba; i++)
	{
		iff = false;
		wynik = 0;
		if (krowy[i].second == 'N')
		{
			for (int j = 0; j < krowye.size(); j++)
			{
				odx = 0;
				ody = 0;
				if (krowy[i].first.second < krowye[j].first) //y
				{
					if (krowy[i].first.first >= krowye[j].second) //x
					{
						odx = krowy[i].first.first - krowye[j].second;
						ody = krowye[j].first - krowy[i].first.second;
						if (odx < ody)
						{
							wynik = ody;
							iff = true;
							break;
						}
					}
				}
			}
		}
		else
		{
			for (int j = 0; j < krowyn.size(); j++)
			{
				odx = 0;
				ody = 0;
				if (krowy[i].first.second > krowyn[j].second)
				{
					if (krowy[i].first.first <= krowyn[j].first)
					{
						odx = krowyn[j].first - krowy[i].first.first;
						ody = krowy[i].first.second - krowyn[j].second;
						if (odx > ody)
						{

							wynik = odx;
							iff = true;
							break;
						}
					}
				}
			}
		}
		if (iff)
		{
			cout << wynik << "\n";
		}
		else
		{
			cout << "Infinity"
				 << "\n";
		}
	}

	return 0;
}