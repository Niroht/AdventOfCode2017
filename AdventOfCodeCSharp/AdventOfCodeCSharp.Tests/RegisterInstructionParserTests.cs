using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdventOfCodeCSharp.Tests
{
    [TestClass]
    public class RegisterInstructionParserTests
    {
        [TestMethod]
        public void RegisterInstructionParser_FindLargestValue_SimpleInstructions()
        {
            // arrange
            var input = new[]
            {
                "b inc 5 if a > 1",
                "a inc 1 if b < 5",
                "c dec -10 if a >= 1",
                "c inc -20 if c == 10"
            };

            // act
            var result = new RegisterInstructionParser().FindLargestValue(input);

            // assert
            Assert.AreEqual(1, result);
        }

        [TestMethod]
        public void RegisterInstructionParser_FindHighestValueEverHeld_SimpleInstructions()
        {
            // arrange
            var input = new[]
            {
                "b inc 5 if a > 1",
                "a inc 1 if b < 5",
                "c dec -10 if a >= 1",
                "c inc -20 if c == 10"
            };

            // act
            var result = new RegisterInstructionParser().FindHighestValueHeld(input);

            // assert
            Assert.AreEqual(10, result);
        }
    }
}
