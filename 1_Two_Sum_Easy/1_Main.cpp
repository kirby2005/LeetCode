#include "iostream"
#include "vector"
#include "map"
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
	map<int, int> numMap;

	for (int i = nums.size() - 1; i >= 0; --i)
	{
		numMap.emplace(nums[i], i);
		auto res = numMap.find(target - nums[i]);
		if (res != numMap.end())
		{
			return vector<int>{ i, res->second };
		}
	}

	return vector<int>{0, 0};
}

int main(int argc, char* argv[])
{
	vector<int> input{2, 7, 11, 15};
	int target = 9;

	auto result = twoSum(input, target);

	return 0;
}