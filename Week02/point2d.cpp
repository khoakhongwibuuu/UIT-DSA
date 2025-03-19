#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;

class pnt
{
private:
	/* data */
	int x;
	int y;
	int z;

public:
	pnt(int x, int y, int z);
	bool operator<(pnt const &other)
	{
		if (this->x - other.x)
			return this->x < other.x;
		else
			return this->y > other.y;
	}
	void Input()
	{
		cin >> x >> y;
	}
	void Output()
	{
		printf("%d %d\n", x, y);
	}
	// ~pnt();
};

pnt::pnt(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z)
{
}

int main()
{
	int n;
	cin >> n;
	vector<pnt> v(n);
	for (int i = 0; i < n; i++)
	{
		v[i].Input();
	}
	sort(v.begin(), v.end());
	for (auto pnt : v)
		pnt.Output();
	return 0;
}