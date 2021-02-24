#include <iostream>

bool isPalindrom(int x)
{
	if (x < 0)
	{
		return false;
	}

	if (x == 0)
	{
		return true;
	}

	int num = x;
	int reverseNum = 0;
	while (num > 0)
	{
		reverseNum += num % 10;
		num /= 10;

		if (num > 0)
		{
			if (reverseNum > 0x7FFFFFFF / 10)  // for test case 1234567899
			{
				return false;
			}
			reverseNum *= 10;
		}
	}

	return x == reverseNum;
}

int main(int argc, char* argv[])
{
	bool result = isPalindrom(313);
	std::cout << result << std::endl;

	return 0;
}