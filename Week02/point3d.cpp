#include <bits/stdc++.h>
using namespace std;

class pnt
{
private:
	int x, y, z;

public:
	pnt(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}

	void Input()
	{
		cin >> x >> y >> z;
	}
	void Output() const
	{
		cout << x << " " << y << " " << z << "\n";
	}

	bool operator<(const pnt &other) const
	{
		if (x != other.x)
			return x < other.x;
		if (y != other.y)
			return y > other.y;
		return z < other.z;
	}
};

int Partition(vector<pnt> &v, int low, int high)
{
	pnt pivot = v[high];
	int i = low - 1;

	for (int j = low; j < high; j++)
	{
		if (v[j] < pivot)
		{
			i++;
			swap(v[i], v[j]);
		}
	}
	swap(v[i + 1], v[high]);
	return i + 1;
}

void I_hate_template(vector<pnt> &v, int low, int high)
{
	if (low < high)
	{
		int pivot = Partition(v, low, high);
		I_hate_template(v, low, pivot - 1);
		I_hate_template(v, pivot + 1, high);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<pnt> v(n);
	for (int i = 0; i < n; i++)
		v[i].Input();

	I_hate_template(v, 0, v.size() - 1);

	for (const auto &p : v)
		p.Output();

	return 0;
}
