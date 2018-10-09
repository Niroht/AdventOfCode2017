using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdventOfCodeCSharp.Tests
{
    [TestClass]
    public class StreamProcessorTests
    {
        [TestMethod]
        public void StreamProcessor_CalculateScore_SingleElement()
        {
            // act
            var result = StreamProcessor.CalculateScore("{}");

            // assert
            Assert.AreEqual(1, result);
        }

        [TestMethod]
        public void StreamProcessor_CalculateScore_NestedElements()
        {
            // act
            var result = StreamProcessor.CalculateScore("{{{}}}");

            // assert
            Assert.AreEqual(6, result);
        }

        [TestMethod]
        public void StreamProcessor_CalculateScore_AdjacentElements()
        {
            // act
            var result = StreamProcessor.CalculateScore("{{},{}}");

            // assert
            Assert.AreEqual(5, result);
        }

        [TestMethod]
        public void StreamProcessor_CalculateStore_AdjacentAndNestedElements()
        {
            // act
            var result = StreamProcessor.CalculateScore("{{{},{},{{}}}}");

            // assert
            Assert.AreEqual(16, result);
        }

        [TestMethod]
        public void StreamProcessor_CalculateScore_OnlyGarbage()
        {
            // act
            var result = StreamProcessor.CalculateScore("{<a>,<a>,<a>,<a>}");

            // assert
            Assert.AreEqual(1, result);
        }

        [TestMethod]
        public void StreamProcessor_CalculateScore_GroupsOfGarbage()
        {
            // act
            var result = StreamProcessor.CalculateScore("{{<ab>},{<ab>},{<ab>},{<ab>}}");

            // assert
            Assert.AreEqual(9, result);
        }

        [TestMethod]
        public void StreamProcessor_CalculateScore_GroupsOfEscapedGarbage()
        {
            // act
            var result = StreamProcessor.CalculateScore("{{<!!>},{<!!>},{<!!>},{<!!>}}");

            // assert
            Assert.AreEqual(9, result);
        }

        [TestMethod]
        public void StreamProcessor_CalculateScore_GroupsOfEscapedAndNonEscapedGarbase()
        {
            // act
            var result = StreamProcessor.CalculateScore("{{<a!>},{<a!>},{<a!>},{<ab>}}");

            // assert
            Assert.AreEqual(3, result);
        }

        [TestMethod]
        public void StreamProcessor_CountGarbageCharacters_EmptyGarbage()
        {
            // act
            var result = StreamProcessor.CountGarbageCharacters("<>");

            // assert
            Assert.AreEqual(0, result);
        }

        [TestMethod]
        public void StreamProcessor_CountGarbageCharacters_RandomCharacters()
        {
            // act
            var result = StreamProcessor.CountGarbageCharacters("<random characters>");

            // assert
            Assert.AreEqual(17, result);
        }

        [TestMethod]
        public void StreamProcessor_CountGarbageCharacters_GarbageTagsInsideGarbage()
        {
            // act
            var result = StreamProcessor.CountGarbageCharacters("<<<<>");

            // assert
            Assert.AreEqual(3, result);
        }

        [TestMethod]
        public void StreamProcessor_CountGarbageCharacters_EscapedGroup()
        {
            // act
            var result = StreamProcessor.CountGarbageCharacters("<{!>}>");

            // assert
            Assert.AreEqual(2, result);
        }

        [TestMethod]
        public void StreamProcessor_CountGarbageCharacters_EscapedEscape()
        {
            // act
            var result = StreamProcessor.CountGarbageCharacters("<!!>");

            // assert
            Assert.AreEqual(0, result);
        }

        [TestMethod]
        public void StreamProcessor_CountGarbageCharacters_TripleEscape()
        {
            // act
            var result = StreamProcessor.CountGarbageCharacters("<!!!>>");

            // assert
            Assert.AreEqual(0, result);
        }

        [TestMethod]
        public void StreamProcessor_CountGarbageCharacters_ComplexTags()
        {
            // act
            var result = StreamProcessor.CountGarbageCharacters("<{o\"i!a,<{i<a>");

            // assert
            Assert.AreEqual(10, result);
        }
    }
}
