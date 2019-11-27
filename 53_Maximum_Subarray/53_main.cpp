#include <iostream>
#include <vector>
using namespace std;
//static vector<int> nums{ -2,1,-3,4,-1,2,1,-5,4 };
static vector<int> nums{ 8,-19,5,-4,20 };

int maxSubArray(vector<int>& nums)
{
	if (nums.size() == 0)
	{
		return 0;
	}

	int currentMax = nums[0];
	int lastMax = currentMax;
	for (int i = 1; i < nums.size(); ++i)
	{
		int max = lastMax > 0 ? lastMax + nums[i] : nums[i];
		lastMax = max;
		currentMax = currentMax >= max ? currentMax : max;
	}
	
	return currentMax;
}

int main(int argc, char* argv[])
{
	int result = maxSubArray(nums);

	//getchar();
}