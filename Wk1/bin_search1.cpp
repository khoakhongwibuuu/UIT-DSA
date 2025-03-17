#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;

int bin_search(vector<int> &v, int low, int high, int x, int &cnt)
{
	if (high >= low)
	{
		cnt++;
		int mid = low + (high - low) / 2;
		if (v[mid] == x)
			return mid;
		if (v[mid] > x)
			return bin_search(v, low, mid - 1, x, cnt);
		return bin_search(v, mid + 1, high, x, cnt);
	}
	return -1;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int x;
	cin >> x;
	int cnt = 0;
	int res = bin_search(v, 0, n - 1, x, cnt);
	if (res - 0xFFFFFFFF)
		cout << res << "\n"
			 << cnt;
	else
		cout << -1;
	return 0;
}