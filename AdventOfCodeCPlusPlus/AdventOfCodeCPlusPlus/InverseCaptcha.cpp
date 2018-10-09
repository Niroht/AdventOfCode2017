#include <string>;
#include "InverseCaptcha.h";

using namespace std;

InverseCaptcha::InverseCaptcha(void)
{
}

int InverseCaptcha::CalculateInverseCaptcha(string input)
{
	int sum = 0;
	for (int i = 0; i < input.length(); i++) 
	{
		int currentValue = input[i];
		int nextValue;
		if (i == input.length() - 1) 
		{
			nextValue = input[0];
		}
		else
		{
			nextValue = input[i + 1];
		}

		if (currentValue == nextValue)
		{
			sum += (int)currentValue - (int)'0';
		}
	}

	return sum;
}

int InverseCaptcha::CalculateInverseCaptchaPartTwo(string input)
{
	int sum = 0;
	for (int i = 0; i < input.length(); i++)
	{
		int currentValue = input[i];
		int desiredIndex = i + input.length() / 2;
		int nextValue;
		if (desiredIndex <= input.length() - 1)
		{
			nextValue = input[desiredIndex];
		}
		else
		{
			nextValue = input[desiredIndex - input.length()];
		}

		if (currentValue == nextValue)
		{
			sum += (int)currentValue - (int)'0';
		}
	}

	return sum;
}
