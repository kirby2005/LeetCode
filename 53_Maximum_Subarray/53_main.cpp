#include <iostream>
#include <vector>
using namespace std;
static vector<int> nums{ -2,1,-3,4,-1,2,1,-5,4 };

int maxSubArray(vector<int>& nums)
{
	if (nums.size() == 0)
	{
		return 0;
	}

	int front = 0, end = 0;
	int lastMax = nums[0];
	int lastArraySum = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		int sum = lastArraySum + nums[i];
		if (sum > lastMax && sum > nums[i])
		{
			end = i;
			lastArraySum = sum;
		}
		else if (lastMax > sum && lastMax > nums[i])
		{
			lastArraySum = sum;
		}
		else if (nums[i] > lastMax && nums[i] > sum)
		{
			front = i;
			end = i;
			lastArraySum = nums[i];
		}
		lastMax = lastMax >= sum ? (lastMax >= nums[i] ? lastMax : nums[i]) : (sum >= nums[i] ? sum : nums[i]);
	}

	return end - front + 1;
}

int main(int argc, char* argv[])
{
	int result = maxSubArray(nums);

	getchar();
}