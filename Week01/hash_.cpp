#include <bits/stdc++.h>
using namespace std;

const int BaseScore = 40;
const int Bonus_Excess = 3;
const int Bonus_Upper = 4;
const int Bonus_Numbers = 5;
const int Bonus_Symbols = 5;
const int Bonus_FlatLower = -15;
const int Bonus_FlatNumber = -35;

const string specialChars = "!@#$%^&*?_~";
const string invalidChars = "./\\‘’',";

bool containsInvalidChar(const string &password)
{
	for (char c : password)
		if (invalidChars.find(c) != string::npos)
			return true;

	return false;
}

int calculateStrength(const string &password)
{
	int length = password.length();

	if (length < 8 || containsInvalidChar(password) || length > 100)
		return -1;

	int numUpper = 0, numNumbers = 0, numSymbols = 0;

	for (char c : password)
	{
		if (isupper(c))
			numUpper++;
		else if (isdigit(c))
			numNumbers++;
		else if (specialChars.find(c) != string::npos)
			numSymbols++;
	}

	int numExcess = length - 8;

	int score = BaseScore +
				(numExcess * Bonus_Excess) +
				(numUpper * Bonus_Upper) +
				(numNumbers * Bonus_Numbers) +
				(numSymbols * Bonus_Symbols);

	if (numUpper > 0 && numNumbers > 0 && numSymbols > 0)
		score += 25;
	else if ((numUpper > 0 && numNumbers > 0) ||
			 (numUpper > 0 && numSymbols > 0) ||
			 (numNumbers > 0 && numSymbols > 0))
		score += 15;

	if (numUpper == 0 && numNumbers == 0 && numSymbols == 0)
		score += Bonus_FlatLower;

	if (numUpper == 0 && numSymbols == 0 && numNumbers == length)
		score += Bonus_FlatNumber;

	return score;
}
int main()
{
	string s;
	getline(cin, s);
	int n = s.length();
	int score = calculateStrength(s);
	if (score == -1)
		cout << "KhongHopLe";
	else if (score < 50)
		cout << "Yeu";
	else if (score < 75)
		cout << "Vua";
	else if (score < 100)
		cout << "Manh";
	else
		cout << "RatManh";

	return 0;
}