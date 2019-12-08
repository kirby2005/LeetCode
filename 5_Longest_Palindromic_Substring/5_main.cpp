#include <string>
using namespace std;

string test = "ababc";
//string test = "cbbd";
//string test = "ac";
//string test = "bb";

string longestPalindrome(string s)
{
	if (s.length() <= 1)
	{
		return s;
	}

	int max = 0;
	int f = 0;
	int e = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		char b = s[i];
		int k = i;
		int j = i;
		while (j < s.length() - 1)
		{
			if (b == s[j + 1])
			{
				++j;
			}
			else
			{
				break;
			}
		}

		while (k > 0 && j < s.length() - 1)
		{
			if (s[k - 1] == s[j + 1])
			{
				k = k - 1;
				j = j + 1;
			}
			else
			{
				break;
			}
		}

		if (j - k > max)
		{
			f = k, e = j;
			max = j - k;
		}
	}

	return s.substr(f, e - f + 1);
}

int main(int argc, char* argv[])
{
	string result = longestPalindrome(test);
}
