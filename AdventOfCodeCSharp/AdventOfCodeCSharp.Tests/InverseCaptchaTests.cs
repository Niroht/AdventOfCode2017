using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AdventOfCodeCSharp.Tests
{
    [TestClass]
    public class InverseCaptchaTests
    {
        [TestMethod]
        public void InverseCaptcha_PairsOfRepeatingDigits()
        {
            // act
            var result = InverseCaptcha.CalculateInverseCaptcha("1122");

            // assert
            Assert.AreEqual(3, result);
        }

        [TestMethod]
        public void InverseCaptcha_AllRepeatingDigits()
        {
            // act
            var result = InverseCaptcha.CalculateInverseCaptcha("1111");

            // assert
            Assert.AreEqual(4, result);
        }

        [TestMethod]
        public void InverseCaptcha_NoRepeatingDigits()
        {
            // act
            var result = InverseCaptcha.CalculateInverseCaptcha("1234");

            // assert
            Assert.AreEqual(0, result);
        }

        [TestMethod]
        public void InverseCaptcha_RepeatingDigitAtEnd()
        {
            // act
            var result = InverseCaptcha.CalculateInverseCaptcha("91212129");

            // assert
            Assert.AreEqual(9, result);
        }

        [TestMethod]
        public void InverseCaptchaPartTwo_PairsOfRepeatingDigits()
        {
            // act
            var result = InverseCaptcha.CalculateInverseCaptchaPartTwo("1212");

            // assert
            Assert.AreEqual(6, result);
        }

        [TestMethod]
        public void InverseCaptchaPartTwo_NoRepeatingDigits()
        {
            // act
            var result = InverseCaptcha.CalculateInverseCaptchaPartTwo("1221");

            // assert
            Assert.AreEqual(0, result);
        }

        [TestMethod]
        public void InverseCaptchaPartTwo_SingleRepeatingSet()
        {
            // act
            var result = InverseCaptcha.CalculateInverseCaptchaPartTwo("123425");

            // assert
            Assert.AreEqual(4, result);
        }

        [TestMethod]
        public void InverseCaptchaPartTwo_TrioOfRepeatingDigits()
        {
            // act
            var result = InverseCaptcha.CalculateInverseCaptchaPartTwo("123123");

            // assert
            Assert.AreEqual(12, result);
        }

        [TestMethod]
        public void InverseCaptchaPartTwo_OneDigitRepeatedFourTimes()
        {
            // act
            var result = InverseCaptcha.CalculateInverseCaptchaPartTwo("12131415");

            // assert
            Assert.AreEqual(4, result);
        }
    }
}
