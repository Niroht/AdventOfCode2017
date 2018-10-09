using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdventOfCodeCSharp
{
    public static class PassphraseValidator
    {
        public static bool BasicValidate(string passphrase)
        {
            return passphrase
                .Split(' ')
                .GroupBy(x => x)
                .All(x => x.Count() == 1);
        }

        public static bool ComplexValidate(string passphrase)
        {
            return passphrase
                .Split(' ')
                .Select(x => string.Concat(x.OrderBy(y => y.ToString())))
                .ToList()
                .GroupBy(x => x)
                .All(x => x.Count() == 1);
        }
    }
}
