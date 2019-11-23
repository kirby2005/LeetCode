#include <iostream>
#include <vector>
using namespace std;

static vector<int> nums{ 1, 3, 5, 6 };
static int target = 5;

int binarySearch_Recursive(const vector<int>& nums, int i, int j, int target)
{
	if (i == j)
	{
		if (nums[i] < target)
		{
			return i + 1;
		}
		else
		{
			return i;
		}
	}

	int m = i + (j - i) / 2;
	if (nums[m] < target)
	{
		return binarySearch_Recursive(nums, m + 1, j, target);
	}
	else
	{
		return binarySearch_Recursive(nums, i, m, target);
	}
}

int binarySearch(const vector<int>& nums, int target)
{
	int i = 0, j = nums.size() - 1;

	while (i < j)
	{
		int m = i + (j - i) / 2;
		if (nums[m] < target)
		{
			i = m + 1;
		}
		else
		{
			j = m;
		}
	}

	if (nums[i] < target)
	{
		return i + 1;
	}

	return i;
}

int searchInsert(vector<int>& nums, int target)
{
	if (nums.size() == 0)
	{
		return 0;
	}
	//return binarySearch_Recursive(nums, 0, nums.size() - 1, target);

	return binarySearch(nums, target);
}



int main(int argc, char* argv[])
{
	int result = searchInsert(nums, target);
	cout << result << endl;
	getchar();

	return 0;
}