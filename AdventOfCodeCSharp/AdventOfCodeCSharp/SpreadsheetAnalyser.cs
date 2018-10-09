using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdventOfCodeCSharp
{
    public static class SpreadsheetAnalyser
    {
        public static int CalculateChecksum(int[][] input)
        {
            var sum = 0;
            
            foreach(var row in input)
            {
                int largestNumber = 0;
                int smallestNumber = 0;

                foreach (var column in row)
                {
                    if (column > largestNumber)
                    {
                        largestNumber = column;
                    }
                    if (smallestNumber == 0 || column < smallestNumber)
                    {
                        smallestNumber = column;
                    }
                }

                sum += largestNumber - smallestNumber;
            }

            return sum;
        }

        public static int SumEvenlyDivisbleValues(int[][] input)
        {
            var sum = 0;

            foreach (var row in input)
            {
                var foundEvenlyDivisibleValue = false;

                for (int column = 0; column < row.Length; column++)
                {
                    for (int i = 0; i < row.Length; i++)
                    {
                        if (i != column && row[column] % row[i] == 0)
                        {
                            sum += row[column] / row[i];
                            foundEvenlyDivisibleValue = true;
                        }

                        if (foundEvenlyDivisibleValue)
                        {
                            break;
                        }
                    }

                    if (foundEvenlyDivisibleValue)
                    {
                        break;
                    }
                }
            }

            return sum;
        }
    }
}
