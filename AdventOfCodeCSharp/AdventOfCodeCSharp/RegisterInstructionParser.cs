using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdventOfCodeCSharp
{
    public class RegisterInstructionParser
    {
        private int _highestValueHeld = 0;

        public int FindLargestValue(string[] input)
        {
            var registers = new Dictionary<string, int>();

            PerformInstructions(input, registers);

            return registers.Max(x => x.Value);
        }

        public int FindHighestValueHeld(string[] input)
        {
            var registers = new Dictionary<string, int>();

            PerformInstructions(input, registers);

            return _highestValueHeld;
        }

        private void PerformInstructions(string[] input, Dictionary<string, int> registers)
        {
            foreach (var instruction in input)
            {
                var parts = instruction.Split(new[] { " " }, StringSplitOptions.RemoveEmptyEntries);

                var registerName = parts[0];
                var modifier = parts[1];
                var modifierAmount = int.Parse(parts[2]);
                var conditionRegister = parts[4];
                var conditionOperator = parts[5];
                var conditionValue = int.Parse(parts[6]);

                if (!registers.ContainsKey(registerName))
                {
                    registers.Add(registerName, 0);
                }
                if (!registers.ContainsKey(conditionRegister))
                {
                    registers.Add(conditionRegister, 0);
                }

                if (!ConditionalIsMet(conditionOperator, conditionValue, registers[conditionRegister]))
                {
                    continue;
                }

                switch (modifier)
                {
                    case "inc":
                        registers[registerName] += modifierAmount;
                        break;
                    case "dec":
                        registers[registerName] -= modifierAmount;
                        break;
                }

                if (registers[registerName] > _highestValueHeld)
                {
                    _highestValueHeld = registers[registerName];
                }
            }
        }

        private static bool ConditionalIsMet(string conditionOperator, int conditionValue, int valueToCheck)
        {
            switch (conditionOperator)
            {
                case ">":
                    return valueToCheck > conditionValue;
                case ">=":
                    return valueToCheck >= conditionValue;
                case "==":
                    return valueToCheck == conditionValue;
                case "!=":
                    return valueToCheck != conditionValue;
                case "<":
                    return valueToCheck < conditionValue;
                case "<=":
                    return valueToCheck <= conditionValue;
                default:
                    return false;
            }
        }
    }
}
