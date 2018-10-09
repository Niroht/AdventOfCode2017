using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdventOfCodeCSharp.Tests
{
    [TestClass]
    public class MemoryReallocatorTests
    {
        [TestMethod]
        public void MemoryReallocator_FindsStepsToFirstRepeatedState()
        {
            // arrange
            var input = new[] { 0, 2, 7, 0 };

            // act
            var result = MemoryReallocator.FindStepsToFirstRepeatedState(input);

            // assert
            Assert.AreEqual(5, result);
        }

        [TestMethod]
        public void MemoryReallocator_FindsSizeOfInfiniteLoop()
        {
            // arrange
            var input = new[] { 0, 2, 7, 0 };

            // act
            var result = MemoryReallocator.FindSizeOfInfiniteLoop(input);

            // assert
            Assert.AreEqual(4, result);
        }
    }
}
