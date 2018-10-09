using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace AdventOfCodeCSharp
{
    public static class TowerAnalyser
    {
        public static string GetBottomTierName(string[] input)
        {
            var nodes = input.Select(ToNode);
            return GetDeepestParent(nodes.First(), nodes).Name;
        }

        public static int GetCorrectWeightOfMisbalancedProgram(string[] input)
        {
            var nodes = input.Select(ToNode).ToArray();
            foreach(var node in nodes)
            {
                AssignChildNodes(node, nodes);
            }

            var deepestParent = GetDeepestParent(nodes.First(), nodes);
            return GetCorrectedWeight(deepestParent);
        }

        private static int GetCorrectedWeight(Node currentNode, int diff = 0)
        {
            var weightGroups = currentNode.ChildNodes.GroupBy(x => x.TowerWeight);

            if (weightGroups.Count() == 1)
            {
                return currentNode.Weight + diff;
            }

            var incorrectTower = weightGroups.First(x => x.Count() == 1).First();
            var correctWeight = weightGroups.First(x => x.Count() > 1).First().TowerWeight;

            return GetCorrectedWeight(incorrectTower, correctWeight - incorrectTower.TowerWeight);
        }

        private static void AssignChildNodes(Node currentNode, IEnumerable<Node> allNodes)
        {
            currentNode.ChildNodes = allNodes.Where(x => currentNode.ChildNames.Contains(x.Name)).ToArray() ?? new Node[] { };
        }

        private static Node GetDeepestParent(Node currentNode, IEnumerable<Node> nodes)
        {
            var parent = nodes.FirstOrDefault(x => x.ChildNames.Contains(currentNode.Name));

            return parent == null ? currentNode : GetDeepestParent(parent, nodes);
        }

        private static Node ToNode(string input)
        {
            var parts = input.Split(new[] { " ", "(", ")", "->", "," }, StringSplitOptions.RemoveEmptyEntries);
            var name = parts[0];
            var weight = parts[1];

            var node = new Node
            {
                Name = name,
                Weight = int.Parse(weight),
            };

            if (parts.Length > 2)
            {
                node.ChildNames = parts.Skip(2).ToArray();
            }

            return node;
        }

        private class Node
        {
            public string Name { get; set; }

            public int Weight { get; set; }

            public string[] ChildNames { get; set; } = new string[] { };

            public IEnumerable<Node> ChildNodes { get; set; }

            public int TowerWeight
            {
                get
                {
                    return Weight + ChildNodes.Sum(x => x.TowerWeight);
                }
            }
        }
    }
}
