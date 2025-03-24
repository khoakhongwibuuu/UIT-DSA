#include <bits/stdc++.h>
using namespace std;

class test
{
private:
	int n;
	int m;
	long long max_height;
	vector<long long> a;
	vector<long long> b;
	vector<pair<int, int>> bestPlan;
	vector<pair<int, int>> plan;

	bool reach(long long H, const vector<long long> &a, const vector<long long> &b, vector<pair<int, int>> &plan)
	{
		plan.clear();
		int pos = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] >= H)
				continue;
			while (pos < b.size() && b[pos] < H - a[i])
				pos++;
			if (pos >= b.size())
				return 0;
			plan.push_back({i, pos});
			pos++;
		}
		return 1;
	}

public:
	test()
	{
		this->max_height = 0;
		cout << "Constructing testcase: " << this << endl;
	}

	~test()
	{
		cout << "Destructing testcase: " << this << endl;
	}

	void input()
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			long long x;
			cin >> x;
			a.push_back(x);
		}
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			long long x;
			cin >> x;
			b.push_back(x);
		}
	}

	void solve()
	{
		long long low = *min_element(a.begin(), a.end());
		long long high = *max_element(a.begin(), a.end()) + *max_element(b.begin(), b.end());
		max_height = low;
		while (low <= high)
		{
			long long mid = (low + high) >> 1;
			if (reach(mid, a, b, plan))
			{
				max_height = mid;
				bestPlan = plan;
				low = mid + 1;
			}
			else
				high = mid - 1;
		}
	}

	void output()
	{
		cout << max_height << " " << bestPlan.size() << "\n";
		for (auto &p : bestPlan)
			cout << p.first + 1 << " " << p.second + 1 << "\n";
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc = 1;
	cin >> tc;
	while (tc--)
	{
		test *testcase = new test();
		testcase->input();
		testcase->solve();
		testcase->output();
		delete testcase;
	}
	return 0;
}
