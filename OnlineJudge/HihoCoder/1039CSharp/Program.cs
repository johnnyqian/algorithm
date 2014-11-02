using System;
using System.IO;

namespace _1039CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            var streamReader = new StreamReader("Input.txt");
            Console.SetIn(streamReader);

            int n = int.Parse(Console.ReadLine());
            while (n-- > 0)
            {
                var str= Console.ReadLine();
                var result = 0;

                for (var c = 'A'; c <= 'C'; c++)
                {
                    for (var i = 0; i <= str.Length; i++)
                    {
                        var newStr = str.Insert(i, c.ToString());
                        result = Math.Max(result, MaximumReduce(newStr));
                    }
                }

                Console.WriteLine(result);
            }
        }

        static int MaximumReduce(string str)
        {
            var tmp = str;

            while (true)
            {
                var index = 0;
                var finished = true;
                while (index < tmp.Length)
                {
                    int count = 1;
                    while ((index + count) < tmp.Length && tmp[index] == tmp[index + count])
                    {
                        count++;
                    }

                    if (count > 1)
                    {
                        finished = false;
                        tmp = tmp.Substring(0, index) + tmp.Substring(index + count); // remove the duplicate char
                    }
                    else
                    {
                        index++;
                    }
                }

                if(finished)
                    return str.Length - tmp.Length;
            }
        }
    }
}