#include <iostream>
#include <vector>
using namespace std;

vector<int> test{ 0,1,100,2,1,0,1,3,2,1,2,1 };

int trap(vector<int>& height)
{
	int size = height.size();
	int max = 0;
	int smax = 0;
	for (int i = 0; i < size; ++i)
	{
		int v = height[i];
		max = v > max ? v : max;
	}
	for (int i = 0; i < size; ++i)
	{
		int v = height[i];
		smax = v > smax && v < max ? v : smax;
	}

	for (int i = 0; i < size; ++i)
	{
		height[i] = height[i] > smax ? smax : height[i];
	}

	int i = 0;
	int leftH = 0;
	int sum = 0;
	while (i < size)
	{
		int vl = height[i];
		if (vl >= leftH)
		{
			leftH = vl;
			++i;
		}
		else
		{
			--i;
			int j = i + 1;
			if (j >= size)
			{
				break;
			}

			int rightH = 0;
			int acc = 0;
			while (j < size && height[j] < leftH)
			{
				acc += height[j];
				++j;
			}

			if (j < size)
			{
				rightH = height[j];
				int minHeight = fmin(leftH, rightH);
				sum += minHeight * (j - (i + 1)) - acc;
			}

			i = j;
		}
	}

	return sum;
}

int main(int argc, char* argv[])
{
	int result = trap(test);
	cout << result << endl;
}