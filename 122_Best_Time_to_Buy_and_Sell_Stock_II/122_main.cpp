#include <vector>
using namespace std;

static vector<int> test = { 7,1,5,3,6,4 };
//static vector<int> test = { 1,2,3,4,5 };
//static vector<int> test = { 7,6,4,3,1 };

int maxProfit(vector<int>& prices)
{
	if (prices.size() <= 1)
	{
		return 0;
	}

	int profit = 0;

	int valley = prices[0];
	int peak = prices[0];
	int lastPrice = prices[0];
	int findMark = 0;
	if (prices[1] >= prices[0])
	{
		findMark = 1;
	}

	int i = 1;
	while (i < prices.size())
	{
		int currentPrice = prices[i];
		if (findMark == 0)  // find valley
		{
			if (currentPrice > lastPrice)
			{
				findMark = 1;
				valley = lastPrice;

				if (i == prices.size() - 1)
				{
					peak = currentPrice;
					profit += peak - valley;
				}
			}
		}
		else   // find peak
		{
			if (currentPrice < lastPrice)
			{
				findMark = 0;
				peak = lastPrice;
				profit += peak - valley;
			}
			else if (i == prices.size() - 1)
			{
				peak = currentPrice;
				profit += peak - valley;
			}
		}

		lastPrice = currentPrice;
		++i;
	}

	return profit;
}

int maxProfit2(vector<int>& prices)
{
	if (prices.size() <= 1)
	{
		return 0;
	}

	int profit = 0;
	int valley = prices[0];
	int peak = prices[0];

	int i = 1;
	while (i < prices.size())
	{
		while (i < prices.size() && prices[i - 1] >= prices[i])
		{
			++i;
		}
		valley = prices[i - 1];

		while (i < prices.size() && prices[i - 1] <= prices[i])
		{
			++i;
		}
		peak = prices[i - 1];
		profit += peak - valley;
	}

	return profit;
}

int main(int argc, char* argv[])
{
	int result = maxProfit(test);
	int result2 = maxProfit2(test);
}