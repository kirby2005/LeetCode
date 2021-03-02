#include <iostream>
#include <vector>
using namespace std;

static vector<int> v1{ 1, 2, 3 };
static vector<int> v2{ 4, 5, 6 };

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> temp;
	vector<int>::const_iterator i1 = nums1.begin();
	vector<int>::const_iterator i2 = nums2.begin();
	for (; i1 != nums1.end() && i2 != nums2.end();)
	{
		if (*i1 <= *i2)
		{
			temp.emplace_back(*i1);
			++i1;
		}
		else
		{
			temp.emplace_back(*i2);
			++i2;
		}
	}

	for (; i1 != nums1.end(); ++i1)
	{
		temp.emplace_back(*i1);
	}

	for (; i2 != nums2.end(); ++i2)
	{
		temp.emplace_back(*i2);
	}

	int size = temp.size();
	if (size == 0)
	{
		return 0;
	}

	if (size == 1)
	{
		return temp[0];
	}

	if ((size & 1) == 0)
	{
		return (temp[size / 2 - 1] + temp[size / 2]) / 2.0;
	}
	else
	{
		return temp[size / 2];
	}
}

int main(int charc, char* argv[])
{
	float ret = findMedianSortedArrays(v1, v2);
	cout << ret << endl;
}