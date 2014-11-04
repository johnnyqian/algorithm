using System;
using System.Collections.Generic;
using System.IO;

namespace _1050CSharp
{
    class Program
    {
        private static int ans;
        private static List<int>[] edges;

        static void Main()
        {
            var streamReader = new StreamReader("Input.txt");
            Console.SetIn(streamReader);

            int n = Convert.ToInt32(Console.ReadLine());
            edges = new List<int>[n + 1];
            for (int i=1;i<n+1;i++)
            {
                edges[i]= new List<int>();
            }

            while (n-- > 1) //边的条数比节点的个数少1
            {
                var operands = Console.ReadLine().Split(' ');
                int point1 = int.Parse(operands[0]);
                int point2 = int.Parse(operands[1]);

                // 使用类似于图的邻接表存储结构, 并且是双向存储的
                edges[point1].Add(point2);
                edges[point2].Add(point1);
            }

            ans = -1;
            DFS(2, 0);

            Console.WriteLine(ans);
        }

        // 树的深度优先搜索
        static int DFS(int curr, int pre)
        {
            // 保留两条最长的子树长度
            int first = 0, second = 0;

            for (int i = 0; i < edges[curr].Count; i++)
            {
                if(edges[curr][i]==pre) // 防止循环搜索
                    continue;

                second = Math.Max(second, DFS(edges[curr][i], curr) + 1);

                if (first < second)
                    Swap(ref first, ref second);
            }

            ans = Math.Max(ans, first + second);

            return first; // 返回当前节点最长的子树长度
        }

        static void Swap(ref int a, ref int b)
        {
            a = a + b;
            b = a - b;
            a = a - b;
        }
    }
}
