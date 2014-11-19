#include <algorithm>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivotValue = arr[low];

    while (low < high)
    {
        while (low < high && pivotValue <= arr[high]) high--;
        if (low < high)
        {
            swap(arr[low], arr[high]);
            low++;
        }

        while (low < high && arr[low] <= pivotValue) low++;
        if (low < high)
        {
            swap(arr[low], arr[high]);
            high--;
        }
    }

    return low;
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int index = partition(arr, low, high);
        quick_sort(arr, low, index - 1);
        quick_sort(arr, index + 1, high);
    }
}