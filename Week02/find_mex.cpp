#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;

int Partition(vector<int> &v, int low, int high)
{
	int pivot = v[high];
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

void QuickSort(vector<int> &v, int low, int high)
{
	if (low < high)
	{
		int pivot = Partition(v, low, high);
		QuickSort(v, low, pivot - 1);
		QuickSort(v, pivot + 1, high);
	}
}

int main()
{
	int n;
	cin >> n;
	if (!n)
	{
		cout << n;
		return 0;
	}
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	QuickSort(a, 0, a.size() - 1);
	if (!a[0])
	{
		for (int i = 0; i < n - 1; i++)
			if (a[i + 1] - a[i] > 1)
			{
				cout << a[i] + 1;
				return 0;
			}
	}
	else
	{
		cout << 0;
	}
	return 0;
}