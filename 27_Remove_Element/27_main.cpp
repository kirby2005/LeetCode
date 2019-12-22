#include <vector>
using namespace std;
static vector<int> nums = { 0,1,2,2,3,0,4,2 };
//static vector<int> nums = { 3, 2, 2, 3 };

int removeElement(vector<int>& nums, int val)
{
	int i = 0;
	int j = nums.size() - 1;
	while (i <= j)
	{
		while (nums[i] == val && i <= j)
		{
			nums[i] = nums[j];
			--j;
		}
		++i;
	}

	return j + 1;
}

int main(int argc, char* argv[])
{
	int result = removeElement(nums, 2);
}