using System;

namespace TrappingRainWater
{
    class Program
    {
        static void Main()
        {
            var example = new[] { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };

            Console.WriteLine(Trap1(example));
            Console.WriteLine(Trap2(example));
        }

        /// <summary>
        /// 时间复杂度是O(2*n)=O(n), 空间上需要一个长度为n的数组，复杂度是O(n)
        /// </summary>
        /// <param name="height"></param>
        /// <returns></returns>
        static int Trap1(int[] height)
        {
            var length = height.Length;
            if (length == 0)
                return 0;

            var dp = new int[length];
            var max = 0;
            for(var i = 0; i<length; i++ )
            {
                dp[i] = max; // 每一个bar左边最大的高度
                max = Math.Max(max, height[i]);
            }

            var result = 0;
            max = 0;
            for (var i = length - 1; i >= 0; i--)
            {
                dp[i] = Math.Min(dp[i], max); // 取左右两边最大高度的较小值，类似木桶原理
                max = Math.Max(max, height[i]); // 每一个bar右边最大的高度

                result += dp[i] - height[i] > 0 ? dp[i] - height[i] : 0;
            }

            return result;
        }

        /// <summary>
        /// 时间复杂度是O(n), 空间复杂度为O(1)
        /// </summary>
        /// <param name="height"></param>
        /// <returns></returns>
        static int Trap2(int[] height)
        {
            var length = height.Length;
            if (length == 0)
                return 0;

            var l = 0;
            var r = length - 1;
            var result = 0;

            while (l < r)
            {
                int min = Math.Min(height[l], height[r]);
                if (height[l] == min)
                {
                    l++;
                    while (l < r && height[l] < min)
                    {
                        result += min - height[l];
                        l++;
                    }
                }
                else
                {
                    r--;
                    while (l < r && height[r] < min)
                    {
                        result += min - height[r];
                        r--;
                    }
                }
            }

            return result;
        }
    }
}
