#include <bits/stdc++.h>

using namespace std;

//counts frequency of a number appearing in a container
//fast but uses lots of memory
//you can even store some numbers that way instead of storing them in a container
//{1,3,2} instead of {1,2,2,2,3,3} 
void count_frequency(const vector<int> &t)
{
	int positive[1000] = {0};
	int negative[1000] = {0};
	for(const &i : t)
	{
		if(i < 0)
		{
			negative[i]++;
		}
		else
		{
			positive[i]++;
		}
	}
}


