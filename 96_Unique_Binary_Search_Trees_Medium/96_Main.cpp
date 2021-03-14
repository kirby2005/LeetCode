#include <iostream>
#include <unordered_map>
using namespace std;

int numTrees(int n)
{
	unordered_map<int, int> dp;

	dp[0] = 1;
	dp[1] = 1;

	int sum = 0;
	for (int i = 0; i <= (n / 2) - 1; ++i)
	{
		int Ri = 0;
		int Rn_i_1 = 0;

		Ri = dp[i];
		Rn_i_1 = dp[n - i - 1];
		sum += (Ri * Rn_i_1) * 2;
	}

	if ((n & 1) > 0)  // if odd
	{
		sum += dp[(n / 2)] * dp[(n / 2)];
	}

	dp[n] = sum;

	return sum;
}

int main(int argc, char* argv[])
{
	int x = numTrees(3);
	for (int i = 0; i <= 19; ++i)
	{
		cout << numTrees(i) << endl;
	}

	return 0;
}