#include <bits/stdc++.h>

using namespace std;

double get_number_from_sequence(double start, double add, int how_many)
{
	if(how_many == 1)
		return start;
	else
		return get_number_from_sequence(start, add, how_many-1) + add;
}



vector<double> get_sequence_numbers(double start, double add, int how_many)
{
	vector<double> sequence_numbers;
	sequence_numbers.push_back(start);
	for (int i = 1; i < how_many; i++)
	{
		sequence_numbers.push_back((sequence_numbers.back() + add));
	}
	return sequence_numbers;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<double> sequence_adding2 = get_sequence_numbers(1, 3.2, 20);
	for(const auto d : sequence_adding2)
	{
		cout << d << " ";
	}
	cout << "\n";

	double number_from_sequence = get_number_from_sequence(1, 3.2, 20);
	cout << number_from_sequence;
	cout << "\n";

	return 0;
}