#include <iostream>
#include <algorithm>
using namespace std;

void print(int arr[], int n);
int partition1(int arr[], int low, int high);
void quick_sort1(int arr[], int low, int high);
int partition2(int arr[], int low, int high);
void quick_sort2(int arr[], int low, int high);

int main()
{
    freopen("Input.txt", "r", stdin);

    int n, tmp;
    cin >> n;
    int* arr1 = (int*)malloc(sizeof(int) * n);
    int* arr2 = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr1[i] = tmp;
        arr2[i] = tmp;
    }

    print(arr1, n);
    quick_sort1(arr1, 0, n - 1);
    print(arr1, n);
    cout << endl;
    print(arr2, n);
    quick_sort2(arr2, 0, n - 1);
    print(arr2, n);
}

void quick_sort1(int arr[], int low, int high)
{
    if (low < high)
    {
        int index = partition1(arr, low, high);
        quick_sort1(arr, low, index - 1);
        quick_sort1(arr, index + 1, high);
    }
}

int partition1(int arr[], int low, int high)
{
    int index = low;
    int pivotValue = arr[high];

    for (int i = low; i < high; i++)
    {
        if (arr[i] <= pivotValue)
        {
            if (i != index)
            {
                swap(arr[i], arr[index]);
            }
            index++;
        }
    }
    swap(arr[index], arr[high]);

    return index;
}

void quick_sort2(int arr[], int low, int high)
{
    if (low < high)
    {
        int index = partition2(arr, low, high);
        quick_sort2(arr, low, index - 1);
        quick_sort2(arr, index + 1, high);
    }
}

int partition2(int arr[], int low, int high)
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

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}