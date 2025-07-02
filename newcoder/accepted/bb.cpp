#include <bits/stdc++.h>
using namespace std;

#define yy cout << "YES\n"
#define no cout << "NO\n"
#define int long long
#define cf cin >> t;
int MOD = 1e9 + 7;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (k == 1) {
        cout << accumulate(a.begin(), a.end(), 0LL) << endl;
        return;
    } else if (k == n) {
        if (a.back() < 0)
            cout << 0 << endl;
        else
            cout << a.back() << endl;
        return;
    } else if (k * 2 > n) {
        int maxx = LLONG_MIN;
        for (int i = k-1; i <= n - k; i++) {
            int tmp = 0;
            for (int j = i; j < i + k; j++) {
                tmp += a[j];
            }
            maxx = max(maxx, tmp);
        }
        cout << maxx << endl;
        return;
    }
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
    }
    vector<vector<int>> dp(n + 1, vector<int>(k, -1e18));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int sum = pre[i] - pre[j];
            for (int p = 0; p < k; p++) {
                if (dp[j][p] != -1e18) {
                    int next_p = (p + 1) % k;
                    dp[i][next_p] =
                        max(dp[i][next_p], dp[j][p] + (next_p == 0 ? sum : 0));
                }
            }
        }
    }

    int ans = -1e18;
    for (int i = 0; i < k; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}