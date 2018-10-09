using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdventOfCodeCSharp
{
    public static class InverseCaptcha
    {
        public static int CalculateInverseCaptcha(string input)
        {
            var sum = 0;
            for (int i = 0; i < input.Length; i++)
            {
                var currentValueAsInt = int.Parse(input[i].ToString());
                var nextIndex = i == input.Length - 1 ? 0 : i + 1;
                var nextValueAsInt = int.Parse(input[nextIndex].ToString());

                if (currentValueAsInt == nextValueAsInt)
                {
                    sum += currentValueAsInt;
                }
            }

            return sum;
        }

        public static int CalculateInverseCaptchaPartTwo(string input)
        {
            var sum = 0;
            for (int i = 0; i < input.Length; i++)
            {
                var currentValueAsInt = int.Parse(input[i].ToString());
                var desiredIndex = (i + input.Length / 2);
                var nextIndex = desiredIndex > input.Length - 1 ? desiredIndex - input.Length : desiredIndex;
                var nextValueAsInt = int.Parse(input[nextIndex].ToString());

                if (currentValueAsInt == nextValueAsInt)
                {
                    sum += currentValueAsInt;
                }
            }

            return sum;
        }
    }
}
