using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdventOfCodeCSharp.Tests
{
    [TestClass]
    public class PassphraseValidatorTests
    {
        [TestMethod]
        public void PassphraseValidator_SimpleValid()
        {
            // act
            var result = PassphraseValidator.BasicValidate("aa bb cc dd ee");

            // assert
            Assert.IsTrue(result);
        }

        [TestMethod]
        public void PassphraseValidator_SimpleInvalid()
        {
            // act
            var result = PassphraseValidator.BasicValidate("aa bb cc dd aa");

            // assert
            Assert.IsFalse(result);
        }

        [TestMethod]
        public void PassphraseValidator_AlmostInvalid()
        {
            // act
            var result = PassphraseValidator.BasicValidate("aa bb cc dd aaa");

            // assert
            Assert.IsTrue(result);
        }

        [TestMethod]
        public void PassphraseValidator_ComplexValidate_Valid()
        {
            // act
            var result = PassphraseValidator.ComplexValidate("abcde fghij");

            // assert
            Assert.IsTrue(result);
        }

        [TestMethod]
        public void PassphraseValidator_ComplexValidate_SingleAnagramInvalid()
        {
            // act
            var result = PassphraseValidator.ComplexValidate("abcde xyz ecdab");

            // assert
            Assert.IsFalse(result);
        }

        [TestMethod]
        public void PassphraseValidator_ComplexValidate_ValidWhenLengthsDifferent()
        {
            // act
            var result = PassphraseValidator.ComplexValidate("a ab abc abd abf abj");

            // assert
            Assert.IsTrue(result);
        }

        [TestMethod]
        public void PassphraseValidator_ComplexValidate_ValidOnlyTwoCharacters()
        {
            // act
            var result = PassphraseValidator.ComplexValidate("iiii oiii ooii oooi oooo");

            // assert
            Assert.IsTrue(result);
        }

        [TestMethod]
        public void PassphraseValidator_ComplexValidate_AllAnagramsInvalid()
        {
            // act
            var result = PassphraseValidator.ComplexValidate("oiii ioii iioi iiio");

            // assert
            Assert.IsFalse(result);
        }
    }
}
