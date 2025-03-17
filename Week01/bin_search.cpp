#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;

int bin_search(vector<int> &v, int low, int high, int x)
{
	if (high >= low)
	{
		int mid = low + (high - low) / 2;
		if (v[mid] == x)
			return 1;
		if (v[mid] > x)
			return bin_search(v, low, mid - 1, x);
		return bin_search(v, mid + 1, high, x);
	}
	return 0;
}

int main()
{
	int n, q;
	cin >> n >> q;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	while (q--)
	{
		int x;
		cin >> x;
		cout << (bin_search(v, 0, n - 1, x) ? "YES" : "NO") << endl;
	}
	return 0;
}