#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	unsigned long long dozmiany = 0;

	vector<int> dro(n);
	vector<int> po(n);
	vector<int> ro(n);

	for (int i = 0; i < n; i++) //wczytywanie
	{
		cin >> dro[i];
		cin >> po[i];
		cin >> ro[i];
	}

	list<pair<int, pair<int, int>>> big; //value level type_food
	int d = 0, p = 0, r = 0;

	int n_n = n;

	for (int i = 0; i < n; i++) //wczytywanie
	{
		if ((dro[i] == 0 && po[i] == 0) ||
			(ro[i] == 0 && po[i] == 0) ||
			(dro[i] == 0 && ro[i] == 0))
		{
			n_n--;
		}
		else
		{
			if (dro[i] > po[i])
			{
				if (dro[i] > ro[i])
				{
					big.push_back(make_pair(dro[i], make_pair(i, 1)));
					d++;
				}
				else
				{
					big.push_back(make_pair(ro[i], make_pair(i, 3)));
					r++;
				}
			}
			else
			{
				if (po[i] > ro[i])
				{
					big.push_back(make_pair(po[i], make_pair(i, 2)));
					p++;
				}
				else
				{
					big.push_back(make_pair(ro[i], make_pair(i, 3)));
					r++;
				}
			}
		}
	}
	big.sort();

	if (n_n > 0)
	{
		if (n_n == 3)
		{
			dozmiany = 0;
			int aa = big.front().second.first;
			big.pop_front();
			int ba = big.front().second.first;
			big.pop_front();
			int ca = big.front().second.first;

			priority_queue<long long> sumyi;
			sumyi.push((dro[aa] + ro[ba] + po[ca]));
			sumyi.push((dro[aa] + ro[ca] + po[ba]));
			sumyi.push((dro[ba] + ro[aa] + po[ca]));
			sumyi.push((dro[ca] + ro[aa] + po[ba]));
			sumyi.push((dro[ba] + ro[ca] + po[aa]));
			sumyi.push((dro[ca] + ro[ba] + po[aa]));

			n_n = 0;

			dozmiany = dozmiany + dro[aa];			dozmiany = dozmiany + ro[aa];			dozmiany = dozmiany + po[aa];
			dozmiany = dozmiany + dro[ba];			dozmiany = dozmiany + ro[ba];			dozmiany = dozmiany + po[ba];
			dozmiany = dozmiany + dro[ca];			dozmiany = dozmiany + ro[ca];			dozmiany = dozmiany + po[ca];
			
			dozmiany = dozmiany - sumyi.top();
		}
		else
		{
			if (!(r && p && d))
			{
				vector<pair<int, pair<int, int>>> pog;

				pog.push_back(big.back());
				big.pop_back();
				if (pog.back().second.second == 1)
					d--;
				else if (pog.back().second.second == 2)
					p--;
				else if (pog.back().second.second == 3)
					r--;

				if (!((!r && p && d) || (r && !p && d) || (r && p && !d)))
				{
					pog.push_back(big.back());
					big.pop_back();
					if (pog.back().second.second == 1)
						d--;
					else if (pog.back().second.second == 2)
						p--;
					else if (pog.back().second.second == 3)
						r--;
				}

				if (!r)
				{
					if (!p)
					{

						if (po[pog[0].second.first] + ro[pog[1].second.first] < po[pog[1].second.first] + ro[pog[0].second.first])
						{
							pog.back().second.second = 2;
							pog.back().first = po[pog[1].second.first];
							big.push_back(pog.back());
							pog.pop_back();

							pog.back().second.second = 3;
							pog.back().first = ro[pog[0].second.first];
							big.push_back(pog.back());
							pog.pop_back();
						}
						else
						{
							pog.back().second.second = 3;
							pog.back().first = ro[pog[1].second.first];
							big.push_back(pog.back());
							pog.pop_back();

							pog.back().second.second = 2;
							pog.back().first = po[pog[0].second.first];
							big.push_back(pog.back());
							pog.pop_back();
						}
					}
					else if (!d)
					{
						{
							if (ro[pog[0].second.first] + dro[pog[1].second.first] < ro[pog[1].second.first] + dro[pog[0].second.first])
							{
								pog.back().second.second = 3;
								pog.back().first = ro[pog[1].second.first];
								big.push_back(pog.back());
								pog.pop_back();

								pog.back().second.second = 1;
								pog.back().first = dro[pog[0].second.first];
								big.push_back(pog.back());
								pog.pop_back();
							}
							else
							{
								pog.back().second.second = 1;
								pog.back().first = dro[pog[1].second.first];
								big.push_back(pog.back());
								pog.pop_back();

								pog.back().second.second = 3;
								pog.back().first = ro[pog[0].second.first];
								big.push_back(pog.back());
								pog.pop_back();
							}
						}
					}
					else
					{
						if (p && d)
						{
							if (!(ro[pog.back().second.first] == 0))
							{
								pog.back().second.second = 3;
								pog.back().first = ro[pog.back().second.first];
								big.push_back(pog.back());
							}
							else
								big.push_back(pog.back());
						}
					}
				}
				else if (!p)
				{
					if (!d)
					{
						if (po[pog[0].second.first] + dro[pog[1].second.first] < po[pog[1].second.first] + dro[pog[0].second.first])
						{
							pog.back().second.second = 2;
							pog.back().first = po[pog[1].second.first];
							big.push_back(pog.back());
							pog.pop_back();

							pog.back().second.second = 1;
							pog.back().first = dro[pog[0].second.first];
							big.push_back(pog.back());
						}
						else
						{
							pog.back().second.second = 1;
							pog.back().first = dro[pog[1].second.first];
							big.push_back(pog.back());
							pog.pop_back();

							pog.back().second.second = 2;
							pog.back().first = po[pog[0].second.first];
							big.push_back(pog.back());
						}
					}
					else
					{
						if (r && d)
						{
							if (!(po[pog.back().second.first] == 0))
							{
								pog.back().second.second = 2;
								pog.back().first = po[pog.back().second.first];
								big.push_back(pog.back());
							}
							else
								big.push_back(pog.back());
						}
					}
				}
				else
				{
					if (r && p)
					{
						if (!(dro[pog.back().second.first] == 0))
						{
							pog.back().second.second = 1;
							pog.back().first = dro[pog.back().second.first];
							big.push_back(pog.back());
						}
						else
							big.push_back(pog.back());
					}
				}
			}
		}
	}
	while (n_n)
	{
		if (big.front().second.second == 1)
		{
			dozmiany = dozmiany + po[big.front().second.first];
			dozmiany = dozmiany + ro[big.front().second.first];
			big.pop_front();
		}
		else if (big.front().second.second == 2)
		{
			dozmiany = dozmiany + dro[big.front().second.first];
			dozmiany = dozmiany + ro[big.front().second.first];
			big.pop_front();
		}
		else if (big.front().second.second == 3)
		{
			dozmiany = dozmiany + po[big.front().second.first];
			dozmiany = dozmiany + dro[big.front().second.first];
			big.pop_front();
		}
		n_n--;
	}
	cout << dozmiany << "\n";
}