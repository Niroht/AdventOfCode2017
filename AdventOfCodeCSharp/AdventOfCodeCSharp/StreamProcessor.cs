using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdventOfCodeCSharp
{
    public static class StreamProcessor
    {
        public static int CalculateScore(string input)
        {
            var depth = 0;
            var score = 0;

            var currentlyReadingGarbage = false;
            var skipNextElement = false;

            foreach (var character in input)
            {
                if (skipNextElement)
                {
                    skipNextElement = false;
                    continue;
                }

                if (currentlyReadingGarbage && character != '>' && character != '!')
                {
                    continue;
                }

                switch (character)
                {
                    case '!':
                        skipNextElement = true;
                        break;
                    case '<':
                        currentlyReadingGarbage = true;
                        break;
                    case '>':
                        currentlyReadingGarbage = false;
                        break;
                    case '{':
                        depth++;
                        break;
                    case '}':
                        score += depth;
                        depth--;
                        break;
                }
            }

            return score;
        }

        public static int CountGarbageCharacters(string input)
        {
            var garbageCharacters = 0;

            var currentlyReadingGarbage = false;
            var skipNextElement = false;

            foreach (var character in input)
            {
                if (skipNextElement)
                {
                    skipNextElement = false;
                    continue;
                }

                if (currentlyReadingGarbage && character != '>' && character != '!')
                {
                    garbageCharacters++;
                    continue;
                }

                switch (character)
                {
                    case '!':
                        skipNextElement = true;
                        break;
                    case '<':
                        currentlyReadingGarbage = true;
                        break;
                    case '>':
                        currentlyReadingGarbage = false;
                        break;
                }
            }

            return garbageCharacters;
        }
    }
}
