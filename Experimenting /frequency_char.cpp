#include <bits/stdc++.h>

#define toDigit(i) (i - '0')

using namespace std;

void generate_freq()
{
	ifstream p("primes.txt");
	ifstream n("normal.txt");
	ifstream np("notprimes.txt");

	ofstream pf("primes_freq.txt");
	ofstream nf("normal_freq.txt");
	ofstream npf("notprimes_freq.txt");

	string s_p;
	string s_n;
	string s_np;

	int t_p[10] = {0};
	int t_n[10] = {0};
	int t_np[10] = {0};

	while (p >> s_p) //primes
	{
		for (auto &i : s_p)
		{
			if (toDigit(i) < 10)
			{
				t_p[toDigit(i)]++;
			}
		}
	}

	while (n >> s_n) //normal
	{
		for (auto &i : s_n)
		{
			if (toDigit(i) < 10)
			{
				t_n[toDigit(i)]++;
			}
		}
	}

	while (np >> s_np) //normal
	{
		for (auto &i : s_np)
		{
			if (toDigit(i) < 10)
			{
				t_np[toDigit(i)]++;
			}
		}
	}

	for (const auto &i : t_p)
	{
		pf << i << "\n";
	}

	for (const auto &i : t_n)
	{
		nf << i << "\n";
	}

	for (const auto &i : t_np)
	{
		npf << i << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	generate_freq();
	return 0;
}