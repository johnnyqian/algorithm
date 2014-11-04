#include <iostream>
#include <algorithm>

using namespace std;

void print(int arr[], int n);
void select_sort(int arr[], int n);

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
    select_sort(arr, n);
    print(arr, n);
}

void select_sort(int arr[], int n)
{
    int minimumIndex;
    for (int i = 0; i < n-1; i++)
    {
        minimumIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minimumIndex])
                minimumIndex = j;
        }

        if (minimumIndex != i)
        {
            swap(arr[i], arr[minimumIndex]);
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