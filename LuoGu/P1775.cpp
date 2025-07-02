#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define PII pair<int, int>
#define dbg(x) std::cout << #x << ":" << x << " "
#define MP make_pair
#define PB push_back
#define rep(i, x, n) for (int i = x; i <= n; i++)
#define dep(i, x, n) for (int i = x; i >= n; i--)
#define arrout(a, n) rep(i, 1, n) std::cout << a[i]
#define arrin(a, n) rep(i, 1, n) std::cin >> a[i]
#define endl '\n'
const int N = 40005;
int a[N], pre[N], dp[N][N], flag[N][N];
void solve() {
    int n;
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    memset(flag, 0, sizeof(flag));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
        dp[i][i] = 0;
        flag[i][i] = i;
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1, j; (j = i + len - 1) <= n; i++) {
            for (int k = flag[i][j - 1]; k <= flag[i + 1][j]; k++) {
                if (dp[i][k] + dp[k + 1][j] + pre[j] - pre[i - 1] < dp[i][j]) {
                    dp[i][j] = dp[i][k] + dp[k + 1][j] + pre[j] - pre[i - 1];
                    flag[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][n] << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}