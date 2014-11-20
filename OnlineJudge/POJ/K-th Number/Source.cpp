#include <iostream>
#include <algorithm>

using namespace std;

typedef struct node
{
    int value;
    int index;
};

int partition(node arr[], int low, int high)
{
    int pivotValue = arr[low].value;

    while (low < high)
    {
        while (low < high && pivotValue <= arr[high].value) high--;
        if (low < high)
        {
            swap(arr[low], arr[high]);
            low++;
        }

        while (low < high && arr[low].value <= pivotValue) low++;
        if (low < high)
        {
            swap(arr[low], arr[high]);
            high--;
        }
    }

    return low;
}

void quick_sort(node arr[], int low, int high)
{
    if (low < high)
    {
        int index = partition(arr, low, high);
        quick_sort(arr, low, index - 1);
        quick_sort(arr, index + 1, high);
    }
}

int main()
{
    int n, m, i, j, k ,t;
    node arr[100001];
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (t = 1; t <= n; t++)
        {
            scanf("%d", &arr[t].value);
            arr[t].index = t;
        }

        quick_sort(arr, 1, n + 1);

        while (m--)
        {
            scanf("%d%d%d", &i, &j, &k);
            for (t = 1; t <= n; t++)
            {
                if (arr[t].index >= i && arr[t].index <= j)
                {
                    if (--k==0)
                        break;
                }
            }

            printf("%d\n", arr[t].value);
        }
    }

    return 0;
}