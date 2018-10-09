using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdventOfCodeCSharp
{
    public static class MemoryReallocator
    {
        public static int FindStepsToFirstRepeatedState(int[] input)
        {
            var clonedInput = input.Select(x => x).ToArray();
            var steps = 0;
            var stateList = new List<int[]>();

            while (!stateList.Any(x => x.SequenceEqual(clonedInput)))
            {
                var blockAddIndex = 0;

                stateList.Add(clonedInput.Select(x => x).ToArray());

                var highestElementValue = clonedInput.Max();
                
                for (int i = 0; i < clonedInput.Length; i++)
                {
                    if (clonedInput[i] == highestElementValue)
                    {
                        clonedInput[i] = 0;
                        blockAddIndex = i == clonedInput.Length - 1 ? 0 : i + 1;
                        break;
                    }
                }

                while (highestElementValue > 0)
                {
                    clonedInput[blockAddIndex]++;
                    highestElementValue--;
                    blockAddIndex = blockAddIndex == clonedInput.Length - 1 ? 0 : blockAddIndex + 1;
                }

                steps++;
            }

            return steps;
        }

        public static int FindSizeOfInfiniteLoop(int[] input)
        {
            var clonedInput = input.Select(x => x).ToArray();
            var loopSize = 0;
            var stateList = new List<int[]>();

            while (true)
            {
                var repeats = stateList.Count(x => x.SequenceEqual(clonedInput));

                if (repeats == 1)
                {
                    loopSize++;
                }
                if (repeats == 2)
                {
                    break;
                }

                var blockAddIndex = 0;

                stateList.Add(clonedInput.Select(x => x).ToArray());

                var highestElementValue = clonedInput.Max();

                for (int i = 0; i < clonedInput.Length; i++)
                {
                    if (clonedInput[i] == highestElementValue)
                    {
                        clonedInput[i] = 0;
                        blockAddIndex = i == clonedInput.Length - 1 ? 0 : i + 1;
                        break;
                    }
                }

                while (highestElementValue > 0)
                {
                    clonedInput[blockAddIndex]++;
                    highestElementValue--;
                    blockAddIndex = blockAddIndex == clonedInput.Length - 1 ? 0 : blockAddIndex + 1;
                }
            }

            return loopSize;
        }
    }
}
