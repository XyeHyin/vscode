#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 2e5 + 5;
ll a[N], b[N], dp[N][2][2], ten[N];
char s1[N], s2[N];
int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s%s", s1 + 1, s2 + 1);
    for (int i = 1; i <= n; i++)
    {
        a[i] = s1[i] - '0';
        b[i] = s2[i] - '0';
    }
    ten[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        ten[i] = ten[i - 1] * 10 % mod;
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + a[i] * ten[n - i] % mod);
                if (a[i] > b[i] && j == 0)
                {
                    dp[i][1][1] = min(dp[i][1][1], dp[i - 1][j][k] + b[i] * ten[n - i] % mod);
                }
                else if (a[i] < b[i] && j == 0)
                {
                    dp[i][0][1] = min(dp[i][0][1], dp[i - 1][j][k] + b[i] * ten[n - i] % mod);
                }
                else
                {
                    dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][k] + b[i] * ten[n - i] % mod);
                }
            }
        }
    }
    printf("%lld\n", min(dp[n][0][1], dp[n][1][1]) % mod);
    return 0;
}