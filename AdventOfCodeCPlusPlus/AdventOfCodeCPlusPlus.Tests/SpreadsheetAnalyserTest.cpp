#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\AdventOfCodeCPlusPlus\SpreadsheetAnalyser.h";

#include <vector>;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace AdventOfCode2017Tests
{
	TEST_CLASS(SpreadsheetAnalyserTest)
	{
	public:

		TEST_METHOD(SpreadsheetAnalyser_CalculatesChecksum)
		{
			// arrange
			SpreadsheetAnalyser spreadsheetAnalyser;
			std::vector<std::vector<int>> input {
				{  5, 1, 9, 5},
				{ 7, 5, 3},
				{ 2, 4, 6, 8}
			};

			// act
			int result = spreadsheetAnalyser.CalculateChecksum(input);

			// assert
			Assert::AreEqual(18, result);
		}

		TEST_METHOD(SpreadsheetAnalyser_SumsEvenlyDivisibleValues)
		{
			// arrange
			SpreadsheetAnalyser spreadsheetAnalyser;
			std::vector<std::vector<int>> input{
				{ 5, 9, 2, 8 },
				{ 9, 4, 7, 3 },
				{ 3, 8, 6, 5 }
			};

			// act
			int result = spreadsheetAnalyser.SumEvenlyDivisibleValues(input);

			// assert
			Assert::AreEqual(9, result);
		}
	};
}