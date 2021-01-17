#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<long long> liczby;
	long a;
	long b;
	long c;

	for (int i = 0; i < 7; i++)
	{
		cin >> a;
		liczby.push_back(a);
	}

	sort(liczby.begin(), liczby.end());

	a = liczby[0];
	b = liczby[1];
	c = (liczby[6] - (a + b));
	cout << a << " " << b << " " << c << "\n";

	return 0;
}