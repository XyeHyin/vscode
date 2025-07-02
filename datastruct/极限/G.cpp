#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main() {
    int n, m;
    cin >> n >> m;
    int tmp = 0;
    vector<int> a(n);
    a[0] = 0;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        tmp += x;
        a[i] = tmp;
    }
    vector<vector<int>> dp(n, vector<int>(m + 1, 0x3f3f3f3f));
    vector<vector<int>> minn(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int mid = (i + j) / 2;
            for (int k = i; k <= j; k++) {
                minn[i][j] += abs(a[k] - a[mid]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        dp[i][1] = minn[0][i];
    }
    for (int j = 2; j <= m; j++) {
        for (int i = j - 1; i < n; i++) {
            for (int k = 0; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + minn[k + 1][i]);
        }
    }
    }
    cout<< dp[n - 1][m];
    return 0;
}