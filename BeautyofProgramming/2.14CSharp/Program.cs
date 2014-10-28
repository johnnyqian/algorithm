using System;
using System.IO;
using System.Linq;

namespace _2._14CSharp
{
    class Program
    {
        static void Main()
        {
            var streamReader = new StreamReader("Input.txt");
            Console.SetIn(streamReader);

            string line;
            while ((line = Console.ReadLine()) != null)
            {
                var array = line.Split(' ').Select(int.Parse).ToArray();

                // 1. Brute force approach, O(n^2)
                int max = int.MinValue;
                int sum;
                for (int i = 0; i < array.Length; i++)
                {
                    sum = 0;
                    for (int j = i; j < array.Length; j++)
                    {
                        sum += array[j];
                        if (sum > max)
                            max = sum;
                    }
                }
                Console.WriteLine(max);

                // 2. O(n)
                max = array[0];
                sum = 0;
                foreach (int t in array)
                {
                    if (sum < 0)
                        sum = t;
                    else
                        sum += t;

                    if (sum > max)
                        max = sum;
                }
                Console.WriteLine(max);

                // 3. DP, O(n)
                // 设dp[i] 为前i个元素中，包含第i个元素且和最大的连续子数组，result 为已找到的子数组中和最大的。
                // 对第i+1个元素有两种选择：做为新子数组的第一个元素、放入前面找到的子数组。
                var dp= new int[array.Length];
                dp[0] = array[0];
                int result = array[0];
                for (int i = 0; i < array.Length-1; i++)
                {
                    dp[i + 1] = Math.Max(array[i + 1], dp[i] + array[i + 1]);
                    result = Math.Max(result, dp[i + 1]);
                }
                Console.WriteLine(result);

                Console.WriteLine();
            }
        }
    }
}