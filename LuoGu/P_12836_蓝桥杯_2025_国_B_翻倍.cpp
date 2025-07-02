// name: P_12836_蓝桥杯_2025_国_B_翻倍.cpp
// date 2025-06-23
// author: XyeHyin

#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<unsigned long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    unsigned long long ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            unsigned long long c = (a[i - 1] + a[i] - 1) / a[i];
            int k = (c <= 1 ? 0 : 64 - __builtin_clzll(c - 1));
            a[i] <<= k;
            ans += k;
        }
    }

    cout << ans << "\n";
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