using namespace std;
#include <vector>

static vector<int> nums{ 7,1,5,3,6,4 };
//static vector<int> nums{ 7,6,4,3,1 };

int maxProfit(vector<int>& prices)
{
	int currentMaxProfit = 0;
	int minBuy = prices[0];

	for (int i = 1; i < prices.size(); ++i)
	{
		int testSell = prices[i];
		int profit = testSell - minBuy;

		currentMaxProfit = currentMaxProfit < profit ? profit : currentMaxProfit;
		minBuy = prices[i] < minBuy ? prices[i] : minBuy;
	}

	return currentMaxProfit ;
}

int main(int argc, char* argv[])
{
	int result = maxProfit(nums);
}