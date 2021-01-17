#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int dl_w; //dlugosc wyswietlacza
	int dl_d; //dlugosc dlugu
	int l_op; //liczba operacji

	int n_s;
	int n_w;
	int n_ww;
	int n_z;  //index zewnetrznego do zmiany
	int n_zz; //nowa wartosc dla indexu
	int odp;
	int idozm;
	int temp;
	int k; //chinese iterator XD
	int w;

	cin >> dl_w;
	cin >> l_op;

	dl_d = dl_w - 1;

	char d_w[dl_d + 1];
	char d_z[dl_d + 1];
	bool is_B[dl_d + 1];
	is_B[dl_d] = false;
	d_w[dl_d] = '0';
	d_z[dl_d] = '0';

	for (int i = 0; i < dl_d; i++)
	{
		cin >> d_w[i];
	}
	for (int i = 0; i < dl_d; i++)
	{
		cin >> d_z[i];
	}
	if ((d_w[dl_d] + d_z[dl_d]) % 48 < 10) //last item if add when is afrer i
		is_B[dl_d] = false;
	else
		is_B[dl_d] = true;

	for (int i = dl_d - 1; i >= 0; i--)
	{
		if ((d_w[i] + d_z[i]) % 48 < 9)
			is_B[i] = false;
		else if ((d_w[i] + d_z[i]) % 48 == 9)
		{
			if (is_B[i + 1])
				is_B[i] = true;
			else
				is_B[i] = false;
		}
		else
			is_B[i] = true;
	}

	char op;
	int iwdd = 0;
	while (l_op)
	{
		cin >> op;
		switch (op)
		{
		case 'S':
			iwdd++;
			cin >> n_s;
			idozm = dl_d - n_s;
			temp = (d_w[idozm] + d_z[idozm]) % 48;
			temp = temp % 10;
			if (idozm <= dl_d && is_B[idozm + 1])
			{

				cout << ((temp + 1)%10) << "\n";
			}
			else
				cout << temp << "\n";

			break;
		case 'Z':
			cin >> n_z;
			cin >> n_zz;
			k = dl_d - n_z;
			d_z[k] = n_zz + 48;
			if ((n_zz + d_w[k]) % 48 < 9)
			{
				is_B[k] = false;
			}
			else if ((n_zz + d_w[k]) % 48 == 9)
			{
				if (is_B[k + 1] == true)
					is_B[k] = true;
				else
					is_B[k] = false;
			}
			else if ((n_zz + d_w[k]) % 48 > 9)
			{
				is_B[k] = true;
			}

			if (is_B[k] == true)
			{
				for (int i = k - 1; (d_z[i] + d_w[i]) % 48 == 9; i--)
				{
					is_B[i] = true;
				}
			}
			else
			{
				for (int i = k - 1; (d_z[i] + d_w[i]) % 48 == 9; i--)
				{
					is_B[i] = false;
				}
			}

			break;

		case 'W':
			cin >> n_w;
			cin >> n_ww;
			k = dl_d - n_w;
			d_w[k] = n_ww + 48;
			if ((n_ww + d_z[k]) % 48 < 9)
			{
				is_B[k] = false;
			}
			else if ((n_ww + d_z[k]) % 48 == 9)
			{
				if (is_B[k + 1] == true)
					is_B[k] = true;
				else
					is_B[k] = false;
			}
			else if ((n_ww + d_z[k]) % 48 > 9)
			{
				is_B[k] = true;
			}

			if (is_B[k] == true)
			{
				for (int i = k - 1; (d_z[i] + d_w[i]) % 48 == 9; i--)
					is_B[i] = true;


			}
			else
			{
				for (int i = k - 1; (d_z[i] + d_w[i]) % 48 == 9; i--)
					is_B[i] = false;

			}
			break;

		default:
			break;
		}
		l_op--;
	}
	return 0;
}