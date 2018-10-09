using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdventOfCodeCSharp.Tests
{
    [TestClass]
    public class TowerAnalyserTests
    {
        [TestMethod]
        public void TowerAnalyser_FindsNameOfBottomTier()
        {
            // arrange
            var input = new[]
            {
                "pbga (66)",
                "xhth(57)",
                "ebii(61)",
                "havc(66)",
                "ktlj(57)",
                "fwft(72)->ktlj, cntj, xhth",
                "qoyq(66)",
                "padx(45)->pbga, havc, qoyq",
                "tknk(41)->ugml, padx, fwft",
                "jptl(61)",
                "ugml(68)->gyxo, ebii, jptl",
                "gyxo(61)",
                "cntj(57)"
            };

            // act
            var result = TowerAnalyser.GetBottomTierName(input);

            // assert
            Assert.AreEqual("tknk", result);
        }

        [TestMethod]
        public void TowerAnalyser_FindsWeightOfIncorrectlyWeightedTower()
        {
            // arrange
            var input = new[]
            {
                "pbga (66)",
                "xhth(57)",
                "ebii(61)",
                "havc(66)",
                "ktlj(57)",
                "fwft(72)->ktlj, cntj, xhth",
                "qoyq(66)",
                "padx(45)->pbga, havc, qoyq",
                "tknk(41)->ugml, padx, fwft",
                "jptl(61)",
                "ugml(68)->gyxo, ebii, jptl",
                "gyxo(61)",
                "cntj(57)"
            };

            // act
            var result = TowerAnalyser.GetCorrectWeightOfMisbalancedProgram(input);

            // assert
            Assert.AreEqual(60, result);
        }
    }
}
