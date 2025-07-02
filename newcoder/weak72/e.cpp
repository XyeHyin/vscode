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
const int MOD = 1e9 + 7;
int dp[200005][13];
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        int c;
        if (s[i] == '0' || s[i] == '1') {
            c = s[i] - '0';
            for (int j = 0; j < 13; j++) {
                int nj = (j * 2 + c) % 13;
                dp[i + 1][nj] = (dp[i + 1][nj] + dp[i][j]) % MOD;
            }
        } else {
            for (int d = 0; d <= 1; d++) {
                for (int j = 0; j < 13; j++) {
                    int nj = (j * 2 + d) % 13;
                    dp[i + 1][nj] = (dp[i + 1][nj] + dp[i][j]) % MOD;
                }
            }
        }
    }
    cout << dp[n][0] << endl;
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