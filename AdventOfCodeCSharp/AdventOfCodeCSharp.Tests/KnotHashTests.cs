using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdventOfCodeCSharp.Tests
{
    [TestClass]
    public class KnotHashTests
    {
        [TestMethod]
        public void KnotHash_MultiplyFirstTwoHashedValues_SmallList()
        {
            // act
            var result = KnotHash.MultiplyFirstTwoHashedValues(5, "3,4,1,5");

            // assert
            Assert.AreEqual(12, result);
        }

        [TestMethod]
        public void KnotHash_ComplexHash_EmptyString()
        {
            // act
            var result = KnotHash.OutputHexString(256, string.Empty);

            // assert
            Assert.AreEqual("a2582a3a0e66e6e86e3812dcb672a272", result);
        }

        [TestMethod]
        public void KnotHash_ComplexHash_Letters()
        {
            // act
            var result = KnotHash.OutputHexString(256, "AoC 2017");

            // assert
            Assert.AreEqual("33efeb34ea91902bb2f59c9920caa6cd", result);
        }

        [TestMethod]
        public void KnotHash_ComplexHash_NumbersPassOne()
        {
            // act
            var result = KnotHash.OutputHexString(256, "1,2,3");

            // assert
            Assert.AreEqual("3efbe78a8d82f29979031a4aa0b16a9d", result);
        }

        [TestMethod]
        public void KnotHash_ComplexHash_NumbersPassTwo()
        {
            // act
            var result = KnotHash.OutputHexString(256, "1,2,4");

            // assert
            Assert.AreEqual("63960835bcdc130f0b66d7ff4f6a5a8e", result);
        }
    }
}
