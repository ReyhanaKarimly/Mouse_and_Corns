#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	unsigned int n, m;
	cin >> n >> m;
	unsigned int a = n*m;
	vector<vector<int>> v(n + 1, vector<int>(m + 1, -1));

	v[n - 1][0] = 0;
	v[n][1] = 0;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 1; j <= m; j++)
		{
			cin >> v[i][j];
		}

	}


	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 1; j <= m; j++)
		{

			if (v[i + 1][j] + v[i][j] >= v[i][j - 1] + v[i][j])
			{

				v[i][j] = v[i + 1][j] + v[i][j];

			}
			else if (v[i + 1][j] + v[i][j] < v[i][j - 1] + v[i][j])
			{
				v[i][j] = v[i][j - 1] + v[i][j];
			}



		}

	}


	int i = 0, j = m;
	string s = "";
	while (i != n - 1 || j != 1)
	{

		if (v[i][j - 1] > v[i + 1][j])
		{
			j--;
			s.append("R");

		}
		else
		{
			i++;
			s.append("F");
		}

	}
	reverse(s.rbegin(), s.rend());
	cout << s;
	system("pause");
	return 0;
}