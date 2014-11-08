using System;
using System.Collections.Generic;
using System.Linq;

namespace Combinatorics
{
    public static class Combinatorics
    {
        public static long PermutationCount(int n, int r)
        {
            if (n <= 0 || r <= 0 || r > n)
                throw new ArgumentException("Invalid parameters!");

            //long result = 1;
            //int i = n;
            //while (i > n - r)
            //{
            //    try
            //    {
            //        checked
            //        {
            //            result *= i;
            //        }
            //    }
            //    catch (OverflowException)
            //    {

            //        throw new OverflowException("Arithmetic operation resulted in an overflow.");
            //    }
            //    i--;
            //}
            //return result;

            // use Linq
            return Enumerable.Range(n - r + 1, r).Select(i => (long)i).Aggregate((result, x) => checked(result * x));
        }

        public static long CombinationCount(int n, int r)
        {
            return PermutationCount(n, r) / PermutationCount(r, r);
        }
    }

    public static class Combinatorics<T>
    {
        /// <summary>
        /// 求数组中r个元素的组合
        /// </summary>
        /// <param name="arr">所求数组</param>
        /// <param name="r">选取元素的个数</param>
        /// <returns>数组中r个元素的组合的列表</returns>
        public static List<T[]> GetCombination(T[] arr, int r)
        {
            if (r > arr.Length)
                throw new ArgumentException("Invalid parameters!");

            var indexArr = new int[r];
            var indexArrList = new List<int[]>();
            GetCombination(indexArrList, indexArr, 0, r, arr.Length);

            // 将下标数组列表转换成对应数组中的元素列表
            return indexArrList.Select(x => x.Select(y => arr[y]).ToArray()).ToList();
        }

        /// <summary>
        /// 递归填充数组下标，下标索引依次增大
        /// </summary>
        /// <param name="indexArrList">保存下标数组的列表</param>
        /// <param name="indexArr">下标数组</param>
        /// <param name="start">当前递归开始取数的位置</param>
        /// <param name="r">需要取数的个数</param>
        /// <param name="n">原始数组的大小</param>
        private static void GetCombination(List<int[]> indexArrList, int[] indexArr, int start, int r, int n)
        {
            for (int i = start; i < n - r + 1; i++)
            {
                indexArr[r - 1] = i;
                if (r > 1)
                {
                    GetCombination(indexArrList, indexArr, i + 1, r - 1, n);
                }
                else
                {
                    var temp = new int[indexArr.Length];
                    indexArr.CopyTo(temp, 0);
                    Array.Reverse(temp);
                    indexArrList.Add(temp);
                }
            }
        }

        /// <summary>
        /// 求数组中r个元素的全排列
        /// </summary>
        /// <param name="arr">所求数组</param>
        /// <param name="r">选取元素的个数</param>
        /// <returns>数组中r个元素的全排列列表</returns>
        public static List<T[]> GetPermutation(T[] arr, int r)
        {
            if (r > arr.Length)
                throw new ArgumentException("Invalid parameters!");

            // 将数组中r个元素的组合中的每一组元素进行全排列即可获得原始数组中r个元素的全排列
            var result = new List<T[]>();

            var allCombination = GetCombination(arr, r);
            foreach (T[] combination in allCombination)
            {
                var permutation = new List<T[]>();
                GetPermutation(permutation, combination, 0, r - 1);
                result.AddRange(permutation);
            }

            return result;
        }

        private static void GetPermutation(List<T[]> result, T[] arr, int startIndex, int endIndex)
        {
            if (startIndex < endIndex)
            {
                for (int i = startIndex; i <= endIndex; i++)
                {
                    Swap(ref arr[startIndex], ref arr[i]);
                    GetPermutation(result, arr, startIndex + 1, endIndex);
                    Swap(ref arr[startIndex], ref arr[i]);
                }
            }
            else
            {
                var temp = new T[arr.Length];
                arr.CopyTo(temp, 0);
                result.Add(temp);
            }
        }

        private static void Swap(ref T a, ref T b)
        {
            T temp = a;
            a = b;
            b = temp;
        }
    }
}