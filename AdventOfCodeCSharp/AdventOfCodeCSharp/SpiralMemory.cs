using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdventOfCodeCSharp
{
    public static class SpiralMemory
    {
        public static int FindStepsToOrigin(int position)
        {
            var steps = 0;
            var grid = CreateGrid(position);

            var currentElement = grid.FirstOrDefault(x => x.Value == position);
            while (currentElement.Value != 1)
            {
                var adjacentElements = grid.Where(x => LocationsAdjacent(x, currentElement));
                var minimumValue = adjacentElements.Min(x => x.Value);

                if (minimumValue == currentElement.Value) break;
                currentElement = adjacentElements.First(x => x.Value == minimumValue);

                steps++;
            }

            return steps;
        }

        public static int FindNextValue(int input)
        {
            List<MemoryLocation> locations = new List<MemoryLocation>();

            var currentHorizontalMovement = 1;
            var currentVerticalMovement = 0;

            var horizontalLimit = 1;
            var verticalLimit = 0;

            var currentHorizontalPosition = 0;
            var currentVerticalPosition = 0;
            var nextValue = 1;
            while (nextValue <= input)
            {
                var newLocation = new MemoryLocation { Value = nextValue, Y = currentVerticalPosition, X = currentHorizontalPosition };
                nextValue = locations.Where(x => LocationsAdjacentIncludingDiagonal(x, newLocation)).Sum(x => x.Value);
                newLocation.Value = Math.Max(1, nextValue);
                locations.Add(newLocation);

                if (currentHorizontalMovement != 0 && Math.Abs(currentHorizontalPosition) == horizontalLimit)
                {
                    if (currentHorizontalMovement > 0)
                    {
                        verticalLimit++;
                    }

                    currentVerticalMovement = currentHorizontalMovement > 0 ? -1 : 1;
                    currentHorizontalMovement = 0;
                }
                else if (currentVerticalMovement != 0 && Math.Abs(currentVerticalPosition) == verticalLimit)
                {
                    if (currentVerticalMovement > 0)
                    {
                        horizontalLimit++;
                    }
                    currentHorizontalMovement = currentVerticalMovement > 0 ? 1 : -1;
                    currentVerticalMovement = 0;
                }

                currentHorizontalPosition += currentHorizontalMovement;
                currentVerticalPosition += currentVerticalMovement;
            }

            return nextValue;
        }

        private static bool LocationsAdjacentIncludingDiagonal(MemoryLocation locationOne, MemoryLocation locationTwo)
        {
            if (locationOne.X == locationTwo.X && locationOne.Y == locationTwo.Y)
            {
                return false;
            }

            var horizontallyAdjacent = Math.Abs(locationOne.X - locationTwo.X) <= 1;
            var verticallyAdjacent = Math.Abs(locationOne.Y - locationTwo.Y) <= 1;

            return horizontallyAdjacent && verticallyAdjacent;
        }

        private static bool LocationsAdjacent(MemoryLocation locationOne, MemoryLocation locationTwo)
        {
            var horizontallyAdjacent = Math.Abs(locationOne.X - locationTwo.X) == 1;
            var verticallyAdjacent = Math.Abs(locationOne.Y - locationTwo.Y) == 1;
            var sameHorizontal = Math.Abs(locationOne.X - locationTwo.X) == 0;
            var sameVertical = Math.Abs(locationOne.Y - locationTwo.Y) == 0;

            return horizontallyAdjacent && sameVertical || verticallyAdjacent && sameHorizontal;
        }

        private static IEnumerable<MemoryLocation> CreateGrid(int position)
        {
            List<MemoryLocation> locations = new List<MemoryLocation>();

            var currentHorizontalMovement = 1;
            var currentVerticalMovement = 0;

            var horizontalLimit = 1;
            var verticalLimit = 0;

            var currentHorizontalPosition = 0;
            var currentVerticalPosition = 0;
            for (int i = 1; i <= position; i++)
            {
                locations.Add(new MemoryLocation { Value = i, Y = currentVerticalPosition, X = currentHorizontalPosition });

                if (currentHorizontalMovement != 0 && Math.Abs(currentHorizontalPosition) == horizontalLimit)
                {
                    if (currentHorizontalMovement > 0)
                    {
                        verticalLimit++;
                    }

                    currentVerticalMovement = currentHorizontalMovement > 0 ? -1 : 1;
                    currentHorizontalMovement = 0;
                }
                else if (currentVerticalMovement != 0 && Math.Abs(currentVerticalPosition) == verticalLimit)
                {
                    if (currentVerticalMovement > 0)
                    {
                        horizontalLimit++;
                    }
                    currentHorizontalMovement = currentVerticalMovement > 0 ? 1 : -1;
                    currentVerticalMovement = 0;
                }

                currentHorizontalPosition += currentHorizontalMovement;
                currentVerticalPosition += currentVerticalMovement;
            }

            return locations;
        }

        private class MemoryLocation
        {
            public int Value { get; set; }

            public int X { get; set; }

            public int Y { get; set; }
        }
    }
}
