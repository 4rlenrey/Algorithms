#include <bits/stdc++.h>

using namespace std;

void SieveOfEratosthenes(int n)
{
	ofstream f("primes.txt");
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= n; p++)
	{
		if (prime[p] == true)
		{
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	for (int p = 2; p <= n; p++)
		if (prime[p])
			f << p << "\n";
	f.close();
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	SieveOfEratosthenes(300000);

	return 0;
}