#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> dp(n, INT_MIN);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0] = 1;
    dp[1] = 3;

    return 0;
}