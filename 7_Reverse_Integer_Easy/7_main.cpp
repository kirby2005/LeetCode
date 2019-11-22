#include "math.h"
int reverse(int x)
{
	int digitalCount = 1;
	long temp = abs(x);
	while (temp / 10 > 0)
	{
		++digitalCount;
		temp = temp / 10;
	}

	long result = 0;
	temp = abs(x);
	while (digitalCount > 0)
	{
		result += (temp % 10) * pow(10, digitalCount - 1);
		temp = temp / 10;
		--digitalCount;
	}

	if (result > (1 << 31) - 1 || result < -(1 << 31))
		return 0;

	return x >= 0 ? result : -result;
}

int main(int argc, char* argv[])
{
	int input = -2147483647 - 1;
	int output = reverse(input);

	return 0;
}