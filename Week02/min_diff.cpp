#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int mindiff = INF;
	sort(v.begin(), v.end());
	for (int i = 0; i < n - 1; i++)
		mindiff = min(mindiff, abs(v[i] - v[i + 1]));
	for (int i = 1; i < n; i++)
	{
		if (mindiff == abs(v[i] - v[i - 1]))
			cout << v[i - 1] << " " << v[i] << " ";
	}
	return 0;
}