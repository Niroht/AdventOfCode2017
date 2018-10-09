using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdventOfCodeCSharp.Tests
{
    [TestClass]
    public class MazeNavigatorTests
    {
        [TestMethod]
        public void MazeNavigator_CalculatesStepsToExit()
        {
            // arrange
            var input = new[] { 0, 3, 0, 1, -3 };

            // act
            var result = MazeNavigator.GetNumberOfStepsToExit(input);

            // assert
            Assert.AreEqual(5, result);
        }

        [TestMethod]
        public void MazeNavigator_CalculatesStepsToExit_PartTwo()
        {
            // arrange
            var input = new[] { 0, 3, 0, 1, -3 };

            // act
            var result = MazeNavigator.GetNumberOfStepsToExitPartTwo(input);

            // assert
            Assert.AreEqual(10, result);
        }
    }
}
