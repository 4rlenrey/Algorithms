#include <bits/stdc++.h>

using namespace std;

void Norm(int n)
{
	ofstream f("normal.txt");
	for (int p = 1; p <= n; p++)
		f << p << "\n";
	f.close();
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Norm(300000);
	return 0;
}