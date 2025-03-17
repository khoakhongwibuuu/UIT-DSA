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
	cout << res.size() << endl;
	for (int i : res)
		cout << i << " " << i + 1 << endl;

	return 0;
}