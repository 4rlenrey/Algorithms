#include <bits/stdc++.h>

using namespace std;

void print_vec(const vector<int> &t)
{
	for(const auto &i : t)
		cout << i << " ";
	cout << "\n";
}

vector<int> check_div(const vector<int> &t, int div)
{
	vector<int> divisabel;
	for(const auto &i : t)
	{
		if(i%div == 0)
			divisabel.push_back(i);
	}
	return(divisabel);
}

vector<int> natural_pos_numbers(pair<int,int> range)
{
	vector<int> answer_range;
	int i = 0;
	if(range.first % 2 == 1)
		i = range.first + 1;
	while(i <= range.second)
	{
		answer_range.push_back(i);
		i += 2;
	}
	return answer_range;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	const vector<int> t = {2,4,4,1,1,2,4,1,3,3,1,4,2,3,6}; 
	cout << "Podzielne przez 3 sa: ";
	print_vec(check_div(t, 3));
	cout << "Parzyste z zakresu 5 do 10 sa: ";
	print_vec(natural_pos_numbers(make_pair(5,10)));


	return 0;
}