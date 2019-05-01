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
		if (res != numMap.end() && i != res->second)
		{
			return vector<int>{ i, res->second };
		}
	}

	return vector<int>{0, 0};
}

int main(int argc, char* argv[])
{
	vector<int> input{3, 3};
	int target = 6;

	auto result = twoSum(input, target);

	return 0;
}