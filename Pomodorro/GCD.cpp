#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) //method 1 (inefficient)
{
	while (a != b)
	{
		if (a < b)
			b = b - a;
		else
			a = a - b;
	}
	return a;
}

int gcd2(int a, int b) //method 2 efficient
{
	int temp;
	while(b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}


int lcm(int a, int b) //least common multiple
{
	return (a*b/gcd2(a, b));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << "Greatest common divisor is: " << gcd(16, 24) << "\n";
	cout << "Greatest common divisor is: " << gcd2(16, 24) << "\n";
	cout << "Least common multiple is: " << lcm(16, 24) << "\n";

	return 0;
}