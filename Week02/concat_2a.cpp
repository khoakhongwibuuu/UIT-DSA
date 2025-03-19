
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int Partition(int *a, int low, int high)
{
	int pivot = a[high];
	int i = low - 1;

	for (int j = low; j < high; j++)
	{
		if (a[j] < pivot)
		{
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[high]);
	return i + 1;
}

void QS(int *a, int low, int high)
{
	if (low < high)
	{
		int pivot = Partition(a, low, high);
		QS(a, low, pivot - 1);
		QS(a, pivot + 1, high);
	}
}

void merge(int *a, int n, int *b, int m, int *c)
{
	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		c[idx] = a[i];
		idx++;
	}
	for (int i = 0; i < m; i++)
	{
		c[idx] = b[i];
		idx++;
	}
	QS(c, 0, m + n - 1);
}

int main()
{
	cin.tie(0);
	std::ios::sync_with_stdio(false);
	int n, m;
	int t;
	cin >> t;
	while (cin >> n >> m || t > 0)
	{
		t--;
		int *a = new int[n], *b = new int[m], *c = new int[n + m];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < m; i++)
			cin >> b[i];

		merge(a, n, b, m, c);
		int nc = n + m;
		;
		for (int i = 0; i < nc; i++)
		{
			cout << c[i] << " ";
		}
		delete c;
		cout << endl;
	}
}
