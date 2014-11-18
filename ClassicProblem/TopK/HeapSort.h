#include <iostream>
#include <algorithm>

using namespace std;

void init_heap(int arr[], int n);
void min_heapify(int arr[], int heapSize, int i);

void heap_sort(int arr[], int n)
{
    init_heap(arr, n); // 初始化最小堆

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]); // 把堆顶arr[0]元素与当前最小堆的最后一个元素交换
        min_heapify(arr, i, 0); // 从根节点开始调整
    }
}

void init_heap(int arr[], int n)
{
    // 构建最小堆
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        min_heapify(arr, n, i); // 从下往上调整所有非叶子节点
    }
}

void min_heapify(int arr[], int heapSize, int i)
{
    int lChild = i * 2 + 1;
    int rChild = i * 2 + 2;

    int minIndex = i;
    if (lChild < heapSize && arr[lChild] < arr[minIndex])
    {
        minIndex = lChild;
    }
    if (rChild < heapSize && arr[rChild] < arr[minIndex])
    {
        minIndex = rChild;
    }

    if (minIndex != i)
    {
        swap(arr[i], arr[minIndex]);

        // 递归调整
        min_heapify(arr, heapSize, minIndex);
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}