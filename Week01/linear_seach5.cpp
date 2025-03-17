#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;

void solve()
{
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	if (n == 2)
		cout << 0;

	else if (n == 3)
		cout << v[2] - v[0];

	else
		cout << v[n - 1] + v[n - 2] - v[0] - v[1];

	cout << endl;
}

int main()
{
	int tc = 1;
	cin >> tc;
	while (tc--)
		solve();
	return 0;
}