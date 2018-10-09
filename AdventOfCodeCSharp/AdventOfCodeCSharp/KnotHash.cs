using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdventOfCodeCSharp
{
    public static class KnotHash
    {
        public static int MultiplyFirstTwoHashedValues(int elementCount, string input)
        {
            var list = BuildList(elementCount);

            var session = new HashSession();

            HashList(list, input.Split(',').Select(x => int.Parse(x)).ToArray(), session);

            return list[0] * list[1];
        }

        public static string OutputHexString(int elementCount, string input)
        {
            var list = BuildList(elementCount);

            var parsedAndSaltedInput = input.Select(x => (int)x).Concat(new[] { 17, 31, 73, 47, 23 }).ToArray();

            var session = new HashSession();

            for (int i = 0; i < 64; i++)
            {
                session = HashList(list, parsedAndSaltedInput, session);
            }

            var denseHashList = new List<int>();
            for (int i = 0; i < list.Count(); i += 16)
            {
                var elements = list.Skip(i).Take(16);

                var value = 0;
                foreach(var element in elements)
                {
                    value ^= element;
                }

                denseHashList.Add(value);
            }

            var denseListToHex = denseHashList.Select(x => x.ToString("x2"));
            return string.Join(string.Empty, denseListToHex);
        }

        private static HashSession HashList(List<int> list, int[] input, HashSession session)
        {
            foreach(var entry in input)
            {
                var swapPosition = session.CurrentPosition;
                var elementsToSwap = list.Skip(session.CurrentPosition).Take(entry).ToArray();
                if (session.CurrentPosition + entry >= list.Count())
                {
                    var wrappedElements = list.Take((session.CurrentPosition + entry) - list.Count());
                    elementsToSwap = elementsToSwap.Concat(wrappedElements).ToArray();
                }

                elementsToSwap = elementsToSwap.Reverse().ToArray();

                foreach(var element in elementsToSwap)
                {
                    list[swapPosition] = element;
                    swapPosition = swapPosition == list.Count() - 1 ? 0 : swapPosition + 1;
                }

                var desiredPosition = session.CurrentPosition + session.SkipSize + entry;
                var adjustedPosition = desiredPosition < list.Count() ? desiredPosition : desiredPosition - list.Count();
                while (adjustedPosition >= list.Count())
                {
                    adjustedPosition -= list.Count();
                }

                session.CurrentPosition = adjustedPosition;
                session.SkipSize++;
            }

            return session;
        }

        private static List<int> BuildList(int elementCount)
        {
            var list = new List<int>();
            
            for (int i = 0; i < elementCount; i++)
            {
                list.Add(i);
            }

            return list;
        }

        private class HashSession
        {
            public int CurrentPosition { get; set; }
            public int SkipSize { get; set; }
        }
    }
}
