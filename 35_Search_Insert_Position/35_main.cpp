#include <iostream>
#include <vector>
using namespace std;

static vector<int> nums{ 1, 3, 5, 6 };
static int target = 5;

int binarySearch(const vector<int>& nums, int i, int j, int target)
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
		return binarySearch(nums, m + 1, j, target);
	}
	else
	{
		return binarySearch(nums, i, m, target);
	}
}

int searchInsert(vector<int>& nums, int target)
{
	if (nums.size() == 0)
	{
		return 0;
	}
	return binarySearch(nums, 0, nums.size() - 1, target);
}



int main(int argc, char* argv[])
{
	int result = searchInsert(nums, target);
	cout << result << endl;
	getchar();

	return 0;
}