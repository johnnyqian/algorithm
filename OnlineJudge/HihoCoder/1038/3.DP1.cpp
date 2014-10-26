#include <stdio.h>
#include <string.h>

# define max(a,b) a>b?a:b

int main3()
{
    int n, m, i, j;
    int need[501], value[501], dp[2][100001];
    memset(dp, 0, sizeof(dp));

    freopen("Input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        scanf("%d %d", &need[i], &value[i]);
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            if (j < need[i])
                dp[1][j] = dp[0][j];
            else
                dp[1][j] = max(dp[0][j], dp[0][j-need[i]]+value[i]);
        }
        for (j = 0; j <= m; j++)
        {
            dp[0][j] = dp[1][j];
        }
    }

    printf("%d\n", dp[1][m]);
    return 0;
}