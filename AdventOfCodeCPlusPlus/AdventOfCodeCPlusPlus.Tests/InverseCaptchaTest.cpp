#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\AdventOfCodeCPlusPlus\InverseCaptcha.h";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AdventOfCode2017Tests
{		
	TEST_CLASS(InverseCaptchaTest)
	{
	public:
		
		TEST_METHOD(InverseCaptcha_PairsOfRepeatingDigits)
		{
			// arrange
			InverseCaptcha inverseCaptcha;

			// act
			int result = inverseCaptcha.CalculateInverseCaptcha("1122");

			// assert
			Assert::AreEqual(3, result);
		}

		TEST_METHOD(InverseCaptcha_AllRepeatingDigits)
		{
			// arrange
			InverseCaptcha inverseCaptcha;

			// act
			int result = inverseCaptcha.CalculateInverseCaptcha("1111");

			// assert
			Assert::AreEqual(4, result);
		}

		TEST_METHOD(InverseCaptcha_NoRepeatingDigits)
		{
			// arrange
			InverseCaptcha inverseCaptcha;

			// act
			int result = inverseCaptcha.CalculateInverseCaptcha("1234");

			// assert
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(InverseCaptcha_RepeatingDigitAtEnd)
		{
			// arrange
			InverseCaptcha inverseCaptcha;

			// act
			int result = inverseCaptcha.CalculateInverseCaptcha("91212129");

			// assert
			Assert::AreEqual(9, result);
		}

		TEST_METHOD(InverseCaptchaPartTwo_PairsOfRepeatingDigits)
		{
			// arrange
			InverseCaptcha inverseCaptcha;

			// act
			int result = inverseCaptcha.CalculateInverseCaptchaPartTwo("1212");

			// assert
			Assert::AreEqual(6, result);
		}

		TEST_METHOD(InverseCaptchaPartTwo_NoRepeatingDigits)
		{
			// arrange
			InverseCaptcha inverseCaptcha;

			// act
			int result = inverseCaptcha.CalculateInverseCaptchaPartTwo("1221");

			// assert
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(InverseCaptchaPartTwo_SingleRepeatingSet)
		{
			// arrange
			InverseCaptcha inverseCaptcha;

			// act
			int result = inverseCaptcha.CalculateInverseCaptchaPartTwo("123425");

			// assert
			Assert::AreEqual(4, result);
		}

		TEST_METHOD(InverseCaptchaPartTwo_TrioOfRepeatingDigits)
		{
			// arrange
			InverseCaptcha inverseCaptcha;

			// act
			int result = inverseCaptcha.CalculateInverseCaptchaPartTwo("123123");

			// assert
			Assert::AreEqual(12, result);
		}

		TEST_METHOD(InverseCaptchaPartTwo_OneDigitRepeatedFourTimes)
		{
			// arrange
			InverseCaptcha inverseCaptcha;

			// act
			int result = inverseCaptcha.CalculateInverseCaptchaPartTwo("12131415");

			// assert
			Assert::AreEqual(4, result);
		}
	};
}