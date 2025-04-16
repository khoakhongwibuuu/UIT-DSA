#include <bits/stdc++.h>
using namespace std;

class CustomID
{
public:
	string a;
	int sign;

	CustomID() : sign(1) {}
	CustomID(string x) { *this = x; }
	CustomID(long long x) { *this = to_string(x); }

	void operator=(string b)
	{
		sign = (b[0] == '-') ? -1 : 1;
		a = (b[0] == '-') ? b.substr(1) : b;
		reverse(a.begin(), a.end());
		Remove0();
	}

	void operator=(long long x) { *this = to_string(x); }

	char operator[](int i) const { return a[i]; }
	int size() const { return a.size(); }

	void Remove0()
	{
		while (a.size() > 1 && a.back() == '0')
			a.pop_back();
		if (a == "0")
			sign = 1;
	}

	bool operator==(const CustomID &x) const { return sign == x.sign && a == x.a; }
	bool operator<(const CustomID &b) const
	{
		if (sign != b.sign)
			return sign < b.sign;
		if (a.size() != b.a.size())
			return (a.size() * sign < b.a.size() * b.sign);
		for (int i = a.size() - 1; i >= 0; i--)
			if (a[i] != b.a[i])
				return (a[i] < b.a[i]);
		return false;
	}
	bool operator>(const CustomID &b) const { return !(*this < b || *this == b); }

	friend ostream &operator<<(ostream &out, const CustomID &x)
	{
		if (x.sign == -1)
			out << '-';
		for (int i = x.a.size() - 1; i >= 0; i--)
			out << x.a[i];
		return out;
	}

	friend istream &operator>>(istream &in, CustomID &x)
	{
		string s;
		in >> s;
		x = s;
		return in;
	}
};

class Package
{
public:
	CustomID ID;
	int count;
	bool operator<(const Package &other) const
	{
		if (count != other.count)
			return count > other.count;
		return ID < other.ID;
	}
	bool operator>(const Package &other) const
	{
		return other < *this;
	}
};

void IDSrt(vector<CustomID> &arr, int left, int right)
{
	if (left >= right)
		return;
	CustomID pivot = arr[left + (right - left) / 2];
	int i = left, j = right;

	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	IDSrt(arr, left, j);
	IDSrt(arr, i, right);
}

void pkgSrt(vector<Package> &arr, int left, int right)
{
	if (left >= right)
		return;
	Package pivot = arr[left + (right - left) / 2];
	int i = left, j = right;

	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	pkgSrt(arr, left, j);
	pkgSrt(arr, i, right);
}

int main()
{
	int n;
	cin >> n;
	vector<CustomID> ID_vector(n);
	for (auto &id : ID_vector)
		cin >> id;

	IDSrt(ID_vector, 0, ID_vector.size() - 1);

	vector<Package> vp;
	CustomID PrevID = ID_vector[0];
	int PrevCount = 1;

	for (size_t i = 1; i < ID_vector.size(); i++)
	{
		if (ID_vector[i] == PrevID)
			PrevCount++;
		else
		{
			vp.push_back({PrevID, PrevCount});
			PrevID = ID_vector[i];
			PrevCount = 1;
		}
	}
	vp.push_back({PrevID, PrevCount});

	cout << vp.size();
	return 0;
}
