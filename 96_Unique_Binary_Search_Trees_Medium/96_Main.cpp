#include <iostream>
#include <vector>
using namespace std;

int numTrees(int n)
{
	vector<int> dp;

	dp.push_back(1);
	dp.push_back(1);

	int sum = 0;
	for (int i = 0; i <= n; ++i)
	{
		if (i >= 2)
		{
			int dpN = 0;
			for (int j = 0; j <= i - 1; ++j)
			{
				dpN += dp[j] * dp[i - 1 - j];
			}

			dp.push_back(dpN);
		}
	}


	return dp[n];
}

int main(int argc, char* argv[])
{
	for (int i = 0; i <= 19; ++i)
	{
		cout << numTrees(i) << endl;
	}

	return 0;
}