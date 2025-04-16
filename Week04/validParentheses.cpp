#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;

bool isValid(string s)
{
	stack<int> stc;
	for (char c : s)
	{
		if (c == '[' || c == '(' || c == '{')
			stc.push(c);
		if (c == ']' || c == ')' || c == '}')
		{
			if (stc.empty())
				return 0;
			if ((c == ']' && stc.top() == '[') ||
				(c == ')' && stc.top() == '(') ||
				(c == '}' && stc.top() == '{'))
				stc.pop();
			else
				return 0;
		}
	}
	return stc.empty();
}
int main()
{
	string s;
	getline(cin, s);
	cout << isValid(s);
	return 0;
}