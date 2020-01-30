using namespace std;
#include<iostream>
#include<string>
#include<vector>

vector<string> test = { "flower", "flow", "flight" };
//vector<string> test = { "dog","racecar","car" };

string longestCommonPrefix(vector<string>& strs)
{
	string result = "";

	if (strs.size() > 0)
	{
		string initStr = strs[0];
		for (int index = 0; index < initStr.size(); ++index)
		{
			char mark = initStr[index];
			bool same = true;
			for (int i = 1; i < strs.size(); ++i)
			{
				string str = strs[i];
				if (str.size() > index && mark == str[index])
				{
				}
				else
				{
					same = false;
					break;
				}
			}
			if (same)
			{
				result += mark;
			}
			else
				break;
		}
	}

	return result;
}

int main(int argc, char* argv[])
{
	string result = longestCommonPrefix(test);
	cout << result << endl;
}