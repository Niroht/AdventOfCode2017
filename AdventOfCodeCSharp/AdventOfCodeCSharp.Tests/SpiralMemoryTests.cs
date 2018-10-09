using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdventOfCodeCSharp.Tests
{
    [TestClass]
    public class SpiralMemoryTests
    {
        [TestMethod]
        public void SpiralMemory_StepsToOrigin_AtOrigin()
        {
            // act
            var result = SpiralMemory.FindStepsToOrigin(1);

            // assert
            Assert.AreEqual(0, result);
        }

        [TestMethod]
        public void SpiralMemory_StepsToOrigin_Diagonal()
        {
            // act
            var result = SpiralMemory.FindStepsToOrigin(12);

            // assert
            Assert.AreEqual(3, result);
        }

        [TestMethod]
        public void SpiralMemory_StepsToOrigin_Straight()
        {
            // act
            var result = SpiralMemory.FindStepsToOrigin(23);

            // assert
            Assert.AreEqual(2, result);
        }

        [TestMethod]
        public void SpiralMemory_StepsToOrigin_LargeNumber()
        {
            // act
            var result = SpiralMemory.FindStepsToOrigin(1024);

            // assert
            Assert.AreEqual(31, result);
        }

        [TestMethod]
        public void SpiralMemory_NextValue_LargerThanOne()
        {
            // act
            var result = SpiralMemory.FindNextValue(1);

            // assert
            Assert.AreEqual(2, result);
        }

        [TestMethod]
        public void SpiralMemory_NextValue_LargerThanTwo()
        {
            // act
            var result = SpiralMemory.FindNextValue(2);

            // assert
            Assert.AreEqual(4, result);
        }

        [TestMethod]
        public void SpiralMemory_NextValue_LargerThanFour()
        {
            // act
            var result = SpiralMemory.FindNextValue(4);

            // assert
            Assert.AreEqual(5, result);
        }
        [TestMethod]
        public void SpiralMemory_NextValue_LargerThanFive()
        {
            // act
            var result = SpiralMemory.FindNextValue(5);

            // assert
            Assert.AreEqual(10, result);
        }
    }
}
