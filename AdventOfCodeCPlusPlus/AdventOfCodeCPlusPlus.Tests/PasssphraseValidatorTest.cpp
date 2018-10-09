#include "stdafx.h"
#include "CppUnitTest.h"

#include "../AdventOfCodeCPlusPlus/PassphraseValidator.h";


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace AdventOfCode2017Tests
{
	TEST_CLASS(PassphraseValidatorTest)
	{
	public:

		TEST_METHOD(PassphraseValidator_SimpleValid)
		{
			// arrange
			PassphraseValidator passPhraseValidator;

			// act
			bool result = passPhraseValidator.BasicValidate("aa bb cc dd ee");

			// assert
			Assert::IsTrue(result);
		}

		TEST_METHOD(PassphraseValidator_SimpleInvalid)
		{
			// arrange
			PassphraseValidator passPhraseValidator;

			// act
			bool result = passPhraseValidator.BasicValidate("aa bb cc dd aa");

			// assert
			Assert::IsFalse(result);
		}

		TEST_METHOD(PassphraseValidator_AlmostInvalid)
		{
			// arrange
			PassphraseValidator passPhraseValidator;

			// act
			bool result = passPhraseValidator.BasicValidate("aa bb cc dd aaa");

			// assert
			Assert::IsTrue(result);
		}

		TEST_METHOD(PassphraseValidator_ComplexValidate_Valid)
		{
			// arrange
			PassphraseValidator passPhraseValidator;

			// act
			bool result = passPhraseValidator.ComplexValidate("abcde fghij");

			// assert
			Assert::IsTrue(result);
		}

		TEST_METHOD(PassphraseValidator_ComplexValidate_SingleAnagramInvalid)
		{
			// arrange
			PassphraseValidator passPhraseValidator;

			// act
			bool result = passPhraseValidator.ComplexValidate("abcde xyz ecdab");

			// assert
			Assert::IsFalse(result);
		}

		TEST_METHOD(PassphraseValidator_ComplexValidate_ValidWhenLengthsDifferent)
		{
			// arrange
			PassphraseValidator passPhraseValidator;

			// act
			bool result = passPhraseValidator.ComplexValidate("a ab abc abd abf abj");

			// assert
			Assert::IsTrue(result);
		}

		TEST_METHOD(PassphraseValidator_ComplexValidate_ValidOnlyTwoCharacters)
		{
			// arrange
			PassphraseValidator passPhraseValidator;

			// act
			bool result = passPhraseValidator.ComplexValidate("iiii oiii ooii oooi oooo");

			// assert
			Assert::IsTrue(result);
		}

		TEST_METHOD(PassphraseValidator_ComplexValidate_AllAnagramsInvalid)
		{
			// arrange
			PassphraseValidator passPhraseValidator;

			// act
			bool result = passPhraseValidator.ComplexValidate("oiii ioii iioi iiio");

			// assert
			Assert::IsFalse(result);
		}
	};
}