#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;

int generateRandomNumber(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

int main()
{
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	vector<int> numbers;
	for (int i = 1; i <= 2024; i++)
		numbers.push_back(i);
	random_shuffle(numbers.begin(), numbers.end());
	ofstream out("input.txt");
	for (auto i : numbers)
	{
		out << i << "\n";
	}
	return 0;
}