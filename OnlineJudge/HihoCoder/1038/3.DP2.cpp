#include <stdio.h>
#include <string.h>

# define max(a,b) a>b?a:b

int main4()
{
    int n, m, i, j;
    int need[501], value[501], dp[100001];
    memset(dp, 0, sizeof(dp));

    freopen("Input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        scanf("%d %d", &need[i], &value[i]);
    }

    for (i = 1; i <= n; i++)
    {
        for (j = m; j >= need[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - need[i]] + value[i]);
        }
    }

    printf("%d\n", dp[m]);
    return 0;
}