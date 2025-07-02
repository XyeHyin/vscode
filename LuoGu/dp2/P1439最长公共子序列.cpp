#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] + (a[i] == b[j]));
        }
    }
    cout << dp[n][n] << endl;
}