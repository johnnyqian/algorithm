#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void backtracking(int i);

int n, m, i, j;
int need[501], value[501];
int *choices;
int max = 0;
int currrentNeed = 0, currentValue = 0;

int main2()
{
    freopen("Input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &need[i], &value[i]);
    }

    choices = (int *)malloc(n * sizeof(int));
    memset(choices, 0, n * sizeof(int));

    backtracking(0);

    printf("%d\n", max);
    return 0;
}

void backtracking(int i)
{
    if (i > n - 1)
    {
        if (currentValue > max)
        {
            max = currentValue;
        }
        return;
    }

    if (currrentNeed + need[i] < m)
    {
        choices[i] = 1; // 表示选中第i件奖品

        currrentNeed += need[i];
        currentValue += value[i];

        backtracking(i + 1);

        currrentNeed -= need[i];
        currentValue -= value[i];
    }

    choices[i] = 0; // 表示不选第i件奖品
    backtracking(i + 1);
}