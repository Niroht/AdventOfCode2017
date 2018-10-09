using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdventOfCodeCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            SolveDayOne();

            SolveDayTwo();

            // Day Three's solution is not optimized and takes a while to run
            // SolveDayThree();

            SolveDayFour();

            SolveDayFive();

            // Day Six's solution is not optimized and takes a while to run
            // SolveDaySix();

            SolveDaySeven();

            SolveDayEight();

            SolveDayNine();

            SolveDayTen();

            Console.ReadKey();
        }

        private static void SolveDayOne()
        {
            var dayOneInput = Inputs.DayOne;
            Console.WriteLine("Day One");
            Console.WriteLine(InverseCaptcha.CalculateInverseCaptcha(dayOneInput));
            Console.WriteLine(InverseCaptcha.CalculateInverseCaptchaPartTwo(dayOneInput));
        }

        private static void SolveDayTwo()
        {
            var dayTwoInput = Inputs.DayTwo;
            var dayTwoRows = dayTwoInput.Split(new[] { Environment.NewLine }, StringSplitOptions.None);
            var parsedDayTwoInput = dayTwoRows.Select(x => x.Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(y => int.Parse(y)).ToArray()).ToArray();

            Console.WriteLine("Day Two");
            Console.WriteLine(SpreadsheetAnalyser.CalculateChecksum(parsedDayTwoInput.ToArray()));
            Console.WriteLine(SpreadsheetAnalyser.SumEvenlyDivisbleValues(parsedDayTwoInput.ToArray()));
        }

        private static void SolveDayThree()
        {
            Console.WriteLine("Day Three");
            Console.WriteLine(SpiralMemory.FindStepsToOrigin(361527));
            Console.WriteLine(SpiralMemory.FindNextValue(361527));
        }

        private static void SolveDayFour()
        {
            var dayFourInput = Inputs.DayFour;

            var passPhrases = dayFourInput.Split(new[] { Environment.NewLine }, StringSplitOptions.RemoveEmptyEntries);
            Console.WriteLine("Day Four");
            Console.WriteLine(passPhrases.Count(x => PassphraseValidator.BasicValidate(x)));
            Console.WriteLine(passPhrases.Count(x => PassphraseValidator.ComplexValidate(x)));
        }

        private static void SolveDayFive()
        {
            var parsedInput = Inputs.DayFive.Split(new[] { Environment.NewLine }, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToArray();
            Console.WriteLine("Day Five");

            Console.WriteLine(MazeNavigator.GetNumberOfStepsToExit(parsedInput));
            Console.WriteLine(MazeNavigator.GetNumberOfStepsToExitPartTwo(parsedInput));
        }

        private static void SolveDaySix()
        {
            var parsedInput = Inputs.DaySix.Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToArray();
            Console.WriteLine("Day Six");

            Console.WriteLine(MemoryReallocator.FindStepsToFirstRepeatedState(parsedInput));
            Console.WriteLine(MemoryReallocator.FindSizeOfInfiniteLoop(parsedInput));
        }

        private static void SolveDaySeven()
        {
            var rows = Inputs.DaySeven.Split(new [] { Environment.NewLine }, StringSplitOptions.RemoveEmptyEntries);

            Console.WriteLine("Day Seven");

            Console.WriteLine(TowerAnalyser.GetBottomTierName(rows));
            Console.WriteLine(TowerAnalyser.GetCorrectWeightOfMisbalancedProgram(rows));
        }

        private static void SolveDayEight()
        {
            var rows = Inputs.DayEight.Split(new[] { Environment.NewLine }, StringSplitOptions.RemoveEmptyEntries);
            var parser = new RegisterInstructionParser();

            Console.WriteLine("Day Eight");

            Console.WriteLine(parser.FindLargestValue(rows));
            Console.WriteLine(parser.FindHighestValueHeld(rows));
        }

        private static void SolveDayNine()
        {
            Console.WriteLine("Day Nine");

            Console.WriteLine(StreamProcessor.CalculateScore(Inputs.DayNine));
            Console.WriteLine(StreamProcessor.CountGarbageCharacters(Inputs.DayNine));
        }

        private static void SolveDayTen()
        {
            Console.WriteLine("Day Ten");

            Console.WriteLine(KnotHash.MultiplyFirstTwoHashedValues(256, Inputs.DayTen));
            Console.WriteLine(KnotHash.OutputHexString(256, Inputs.DayTen));
        }
    }
}
