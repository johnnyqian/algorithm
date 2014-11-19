using System;

namespace Combinatorics
{
    class Program
    {
        static void Main()
        {
            var arr = new[] { 1, 2, 3, 4, 5, 6 };

            Console.WriteLine(Combinatorics.CombinationCount(arr.Length, 3));
            Console.WriteLine(Combinatorics.PermutationCount(arr.Length, 3));
            Console.WriteLine();

            var allCombination = Combinatorics<int>.GetCombination(arr, 3);
            foreach (var item in allCombination)
            {
                foreach (var i in item)
                {
                    Console.Write(i);
                }
                Console.Write("\t");
            }

            Console.WriteLine("\n");

            var allPermutation = Combinatorics<int>.GetPermutation(arr, 3);
            foreach (var item in allPermutation)
            {
                foreach (var i in item)
                {
                    Console.Write(i);
                }
                Console.Write("\t");
            }
        }
    }
}