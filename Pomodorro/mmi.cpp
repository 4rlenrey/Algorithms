#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	int temp;
	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int mmi(int a, int b)
{
	int u, w, x, z, q;
	u = 1;
	w = a;
	x = 0;
	z = b;
	while (w != 0)
	{
		if (w < z)
		{
			swap(u, x);
			swap(w, z);
		}
		q = w / z;
		u -= q * x;
		w -= q * z;
	}
	if (z == 1)
	{
		if (x < 0)
		{
			x += b;
		}
		return x;
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if (mmi(12767, 256) > -1)
	{
		cout << mmi(12767, 256) << "\n";
	}
	else
		cout << "NIE ISTNIEJE" << "\n";

		return 0;
}