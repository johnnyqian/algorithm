#include <stdlib.h>

void multiply(int arr[], int n)
{
    int* product = (int*)malloc(sizeof(int)*n);
    int accumulator = 1;

    // from left to right
    for(int i=0; i < n; i++)
    {
        product[i] = accumulator;
        accumulator *= arr[i];
    }

    // reset
    accumulator = 1;

    // from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        product[i] *= accumulator;
        accumulator *= arr[i];
    }

    // replace the original
    for (int i = 0; i < n; i++)
    {
        arr[i] = product[i];
    }
}

int main()
{
    int sample1[5] = { 1, 2, 3, 4, 5 };
    multiply(sample1, 5);

    int sample2[5] = { 1, 3, 5, 7, 9 };
    multiply(sample2, 5);

    return 0;
}