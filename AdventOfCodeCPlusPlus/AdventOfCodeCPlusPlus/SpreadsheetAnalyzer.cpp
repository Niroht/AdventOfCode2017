#include "SpreadsheetAnalyser.h";

#include <vector>;
using namespace std;

SpreadsheetAnalyser::SpreadsheetAnalyser()
{
}

int SpreadsheetAnalyser::CalculateChecksum(std::vector<std::vector<int>> input)
{
	int sum = 0;

	for (int i = 0; i < input.size(); i++)
	{
		std::vector<int> row = input[i];
		int largestNumber = 0;
		int smallestNumber = 0;

		for (int j = 0; j < row.size(); j++)
		{
			int column = row[j];
			if (column > largestNumber)
			{
				largestNumber = column;
			}
			if (smallestNumber == 0 || column < smallestNumber)
			{
				smallestNumber = column;
			}
		}

		sum += largestNumber - smallestNumber;
	}

	return sum;
}

int SpreadsheetAnalyser::SumEvenlyDivisibleValues(std::vector<std::vector<int>> input)
{
	int sum = 0;

	for (int i = 0; i < input.size(); i++)
	{
		std::vector<int> row = input[i];

		bool foundEvenlyDivisibleValue = false;

		for (int j = 0; j < row.size(); j++)
		{
			int column = row[j];
			
			for (int k = 0; k < row.size(); k++)
			{
				if (k != j && row[j] % row[k] == 0)
				{
					sum += row[j] / row[k];
					foundEvenlyDivisibleValue = true;
				}

				if (foundEvenlyDivisibleValue)
				{
					break;
				}
			}

			if (foundEvenlyDivisibleValue)
			{
				break;
			}
		}
	}

	return sum;
}
