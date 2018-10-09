using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdventOfCodeCSharp
{
    public static class MazeNavigator
    {
        public static int GetNumberOfStepsToExit(int[] input)
        {
            // Don't mutate the list that was passed to us
            var clonedInput = input.Select(x => x).ToArray();

            var index = 0;
            var steps = 0;
            while (index < clonedInput.Length && index >= 0)
            {
                var originalIndex = index;
                index += clonedInput[index];
                clonedInput[originalIndex]++;
                steps++;
            }

            return steps;
        }

        public static int GetNumberOfStepsToExitPartTwo(int[] input)
        {
            // Don't mutate the list that was passed to us
            var clonedInput = input.Select(x => x).ToArray();

            var index = 0;
            var steps = 0;
            while (index < clonedInput.Length && index >= 0)
            {
                var originalIndex = index;
                index += clonedInput[index];
                clonedInput[originalIndex]+= clonedInput[originalIndex] >= 3 ? -1 : 1;
                steps++;
            }

            return steps;
        }
    }
}
