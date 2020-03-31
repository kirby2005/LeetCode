#include<iostream>
#include<vector>
using namespace std;

vector<int> test{ 1, 2, 3, 1 };

int findPeakElement(vector<int>& nums)
{
	int i = 0;
	int j = nums.size() - 1;

	while (i < j)
	{
		int middle = (j + i) / 2;

		if (middle + 1 < nums.size() && nums[middle] < nums[middle + 1])
		{
			i = middle + 1;
		}
		else if (middle - 1 >= 0 && nums[middle] < nums[middle - 1])
		{
			j = middle - 1;
		}
		else
		{
			return middle;
		}
	}

	return i;
}

int main(int argc, char* argv[])
{
	int ret = findPeakElement(test);
	cout << ret << endl;
}