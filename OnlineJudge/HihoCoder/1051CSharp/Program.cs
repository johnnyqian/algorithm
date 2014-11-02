using System;
using System.IO;

namespace _1051CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            var streamReader = new StreamReader("Input.txt");
            Console.SetIn(streamReader);

            int t = int.Parse(Console.ReadLine());
            while (t-- > 0)
            {
                var str = Console.ReadLine().Split(' ');
                int n = int.Parse(str[0]);
                int m = int.Parse(str[1]);
                str = Console.ReadLine().Split(' ');

                if (n <= m)
                {
                    Console.WriteLine(100);
                    continue;
                }

                var arr = new int[n];
                for (int i = 0; i < n; i++)
                {
                    arr[i] = int.Parse(str[i]);
                }

                // 补提交卡连续使用才能使得连续提交天数达到最长
                int max = arr[m] - 1;
                for (int i = m + 1; i < n; i++)
                {
                    max = Math.Max(max, arr[i] - arr[i - m - 1] - 1);
                }
                max = Math.Max(max, 100 - arr[n - m - 1]);

                Console.WriteLine(max);
            }
        }
    }
}