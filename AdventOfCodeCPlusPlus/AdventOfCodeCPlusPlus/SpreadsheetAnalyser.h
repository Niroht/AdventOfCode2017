#pragma once
#include <vector>;

using namespace std;

class SpreadsheetAnalyser
{
public:
	SpreadsheetAnalyser();

	int CalculateChecksum(std::vector<std::vector<int>> input);

	int SumEvenlyDivisibleValues(std::vector<std::vector<int>> input);
};

