#include <iostream>
#include <algorithm>

using namespace std;

void print(int arr[], int n);
void bubble_sort1(int arr[], int n);
void bubble_sort2(int arr[], int n);

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
    bubble_sort1(arr1, n);
    print(arr1, n);
    cout << endl;
    print(arr2, n);
    bubble_sort2(arr2, n);
    print(arr2, n);
}

// 大数下沉（经典方法）
void bubble_sort1(int arr[], int n)
{
    bool unOrdered = true;
    for (int i = 1; i < n && unOrdered; i++)  // n-1次循环过程
    {
        unOrdered = false; // 每一轮比较后，如果unOrdered仍旧为false，则表明元素集合已全部排好序，可提前结束整个排序过程
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                unOrdered = true;
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 小数上浮
void bubble_sort2(int arr[], int n)
{
    bool unOrdered = true;
    for (int i = 0; i < n - 1 && unOrdered; i++)  // n-1次循环过程
    {
        unOrdered = false;
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                unOrdered = true;
                swap(arr[j], arr[j - 1]);
            }
        }
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