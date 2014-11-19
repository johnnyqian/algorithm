#include <iostream>
#include <algorithm>
#include "QuickSort.h"

using namespace std;

// 用于检测当数组中有重复的元素时，当前元素是否已经交换过
bool isAlreadySwaped(int arr[], int start, int i)
{
    if (start < i)
    {
        for (int t = start; t < i; t++)
        {
            if (arr[t] == arr[i]) // 若在之前交换过相同值，则返回true
                return true;
        }
    }

    return false;
}

/// <summary>
/// 递归生成全排列
/// </summary>
/// <param name="start">全排列的起始位置</param>
/// <param name="end">全排列的终止位置</param>
void permutation(int arr[], int start, int end)
{
    if (start < end) //还有多个元素待排列，递归产生排列
    {
        for (int i = start; i <= end; i++)
        {
            if (isAlreadySwaped(arr, start, i))
                continue;

            quick_sort(arr, start, end); // 此处排序主要是为了生成字典序全排列，否则递归会打乱字典序

            swap(arr[start], arr[i]);
            permutation(arr, start + 1, end);
            swap(arr[start], arr[i]);
        }
    }
    else //只剩下1个元素
    {
        for (int i = 0; i <= end; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}

int main()
{
    int arr[4] = { 1, 2, 3, 4};
    permutation(arr, 0, 3);
    cout << endl;
    int arr2[4] = { 1, 1, 9, 9 };
    permutation(arr2, 0, 3);

    return 0;
}