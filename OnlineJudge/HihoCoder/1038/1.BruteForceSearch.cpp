#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void decimal2binary(int i, int x[]);

int main1()
{
    int n, m, i, j;
    int need[501], value[501], bag[100010];
    int max;
    int *choices;

    freopen("Input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &need[i], &value[i]);
    }

    memset(bag, 0, sizeof(bag));

    // brute force search, enumerate all the possible choices, the time complexity is O(2^n).
    // This approach will lead Time Limit Exceeded in hihoCoder.
    max = 0;
    choices = (int *)malloc(n * sizeof(int));
    memset(choices, 0, n * sizeof(int));

    for (i = 0; i < pow(2.0, n); i++)
    {
        decimal2binary(i, choices);

        int temp_v = 0, temp_n = 0;
        for (j = 0; j < n; j++)
        {
            if (choices[j] == 1)
            {
                temp_v += value[j];
                temp_n += need[j];
            }
        }
        if (temp_n <= m && temp_v > max)
        {
            max = temp_v;
        }
    }

    printf("%d\n", max);
    return 0;
}

void decimal2binary(int i, int x[])
{
    int index = 0;
    while (i != 0)
    {
        x[index] = i % 2;
        i = i / 2;
        index++;
    }
}