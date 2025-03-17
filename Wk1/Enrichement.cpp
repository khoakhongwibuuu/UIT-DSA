#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;

int sum_surrounding(vector<vector<int>> &v, int i, int j)
{
	return v[i - 1][j - 1] + v[i][j - 1] + v[i + 1][j - 1] + v[i - 1][j] +
		   v[i - 1][j + 1] + v[i][j + 1] + v[i + 1][j + 1] + v[i + 1][j] + v[i][j];
}

int main()
{
	int n, m, sum = 0;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
			sum += v[i][j];
		}
	}
	int res = INF;
	// cout << sum << endl;
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < m - 1; j++)
		{
			int area = sum_surrounding(v, i, j);
			res = min(res, area);
		}
	}
	cout << res;
	return 0;
}