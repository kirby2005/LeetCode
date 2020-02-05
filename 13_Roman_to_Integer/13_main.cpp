using namespace std;
#include<iostream>
#include<string>
#include<vector>
#include<map>

vector<string> tests = { "III", "IV", "IX", "LVIII", "MCMXCIV" };

int romanToInt(string s)
{
	map<char, int> romanMap =
	{
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000},
	};

	int sum = 0;
	int i = 0;
	while (i < s.size())
	{
		int num = 0;
		int j = i + 1;
		const char ci = s[i];
		if (j < s.size())
		{
			const char cj = s[j];
			if (romanMap[cj] > romanMap[ci])
			{
				++i;
				num = romanMap[cj] - romanMap[ci];
			}
			else
			{
				num = romanMap[ci];
			}
		}
		else
		{
			num = romanMap[ci];
		}
		sum += num;

		++i;
	}

	return sum;
}

int main(int argc, char* argv[])
{
	for (int i = 0; i < tests.size(); ++i)
	{
		string& test = tests[i];
		int result = romanToInt(test);
		cout << result << endl;
	}
}