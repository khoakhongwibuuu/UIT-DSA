#include <iostream>
#include <string>

struct Pair
{
	int value;
	int pos;
	bool operator<(const Pair &other) const
	{
		if (this->value == other.value)
			return this->pos < other.pos;
		return this->value < other.value;
	}
	bool operator>(const Pair &other) const
	{
		return other < *this;
	}
};

struct Record
{
	int value;
	int first;
	int last;
};

int cmpPairs(const void *a, const void *b)
{
	Pair *p1 = (Pair *)a;
	Pair *p2 = (Pair *)b;
	if (p1->value == p2->value)
		return p1->pos - p2->pos;
	return p1->value - p2->value;
}

void IDSrt(Pair *arr, int left, int right)
{
	if (left >= right)
		return;
	Pair pivot = arr[left + (right - left) / 2];
	int i = left, j = right;

	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	IDSrt(arr, left, j);
	IDSrt(arr, i, right);
}

int main()
{
	int n, q;
	std::cin >> n >> q;

	Pair *arr = (Pair *)malloc(n * sizeof(Pair));
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i].value;
		arr[i].pos = i + 1;
	}

	IDSrt(arr, 0, n - 1);

	Record *dp = (Record *)malloc(n * sizeof(Record));
	int idx = 0;

	dp[idx].value = arr[0].value;
	dp[idx].first = arr[0].pos;
	dp[idx].last = arr[0].pos;

	for (int i = 1; i < n; i++)
	{
		if (arr[i].value == dp[idx].value)
		{
			dp[idx].last = arr[i].pos;
		}
		else
		{
			idx++;
			dp[idx].value = arr[i].value;
			dp[idx].first = arr[i].pos;
			dp[idx].last = arr[i].pos;
		}
	}
	idx++;

	for (int i = 0; i < q; i++)
	{
		int type, y;
		std::string s;
		std::cin >> s >> type >> y;

		int lo = 0, hi = idx - 1, found = 0, ans = -1;
		while (lo <= hi)
		{
			int mid = (lo + hi) / 2;
			if (dp[mid].value == y)
			{
				found = 1;
				if (type == 1)
					ans = dp[mid].first;
				else if (type == 2)
					ans = dp[mid].last;
				break;
			}
			else if (dp[mid].value < y)
			{
				lo = mid + 1;
			}
			else
			{
				hi = mid - 1;
			}
		}
		std::cout << (found ? ans : -1) << '\n';
	}

	free(arr);
	free(dp);

	return 0;
}
