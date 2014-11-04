#include <iostream>
#include <algorithm>

using namespace std;

void print(int arr[], int n);
void insert_sort(int arr[], int n);

int main()
{
    freopen("Input.txt", "r", stdin);

    int n;
    cin >> n;
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    print(arr, n);
    insert_sort(arr, n);
    print(arr, n);
}

void insert_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int tmp = arr[i + 1]; // 当前待插入的值

        // 寻找插入的位置
        int index = i;
        while (index>-1 && tmp< arr[index])
        {
            // 向后腾挪位置
            arr[index + 1] = arr[index];
            index--;
        }
        arr[index + 1] = tmp;
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