#include <iostream>
#include <time.h>
#include "HeapSort.h"

using namespace std;

int main()
{
    int n = 1000;
    int* arr = (int*)malloc(sizeof(int)*n);

    // seed the random-number generator with current time and generate a large set of data
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }

    cout << "Original " << n << " numbers:" << endl;
    print(arr, n);

    int k = 10;
    int* result = (int*)malloc(sizeof(int)*k);
    for (int i = 0; i < k; i++)
    {
        result[i] = arr[i];
    }

    init_heap(result, k); // initialize a min-heap

    for (int i = k; i < n; i++)
    {
        if (arr[i] > result[0])
        {
            result[0] = arr[i];
            min_heapify(result, k, 0);
        }
    }

    // sort
    for (int i = k - 1; i > 0; i--)
    {
        swap(result[0], result[i]);
        min_heapify(result, i, 0); // heapify the heap from root node
    }

    cout << "Top " << k << " numbers:" << endl;
    print(result, k);
}