#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n, 0);
	vector<int> res;

	for (int i = 0; i < n; i++)
		cin >> v[i];
	int x;
	cin >> x;
	for (int i = 0; i < n; i++)
		if (v[i] == x)
			res.push_back(i);
	for (int i = n - 1; i >= 0; i--)
		if (v[i] == x)
			res.push_back(n - 1 - i);
	if (!res.size())
	{
		cout << -1;
		return 0;
	}
	else
	{
		for (int i : res)
			cout << i << endl << i + 1 << endl;
	}

	return 0;
}