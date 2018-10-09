using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdventOfCodeCSharp.Tests
{
    [TestClass]
    public class SpreadsheetAnalyserTests
    {
        [TestMethod]
        public void SpreadsheetAnalyser_CalculatesChecksum()
        {
            // arrange
            var input = new[]
            {
                new [] {5, 1, 9, 5},
                new [] { 7, 5, 3},
                new [] { 2, 4, 6, 8}
            };

            // act
            var result = SpreadsheetAnalyser.CalculateChecksum(input);

            // assert
            Assert.AreEqual(18, result);
        }

        [TestMethod]
        public void SpreadsheetAnalyser_SumsEvenlyDivisibleValues()
        {
            // arrange
            var input = new[]
            {
                new [] {5, 9, 2, 8},
                new [] {9, 4, 7, 3},
                new[] {3, 8, 6, 5}
            };

            // act
            var result = SpreadsheetAnalyser.SumEvenlyDivisbleValues(input);

            // assert
            Assert.AreEqual(9, result);
        }
    }
}
