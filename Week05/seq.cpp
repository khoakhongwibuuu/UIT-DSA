#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;

int main()
{
	map<int, int> mp;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		mp[x]++;
	}

	int ans = 0;
	for (const auto& it : mp)
	{

		if (it.second > it.first)
		{
			ans += (it.second - it.first);
		}
		else if (it.second < it.first)
		{
			ans += it.second;
		}
	}

	cout << ans;
	return 0;
}