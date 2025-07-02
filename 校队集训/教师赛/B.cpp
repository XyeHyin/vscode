#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        for (int i = l; i <= r; i++) {
            a[i] += x;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] < 0) {
            cout << 0;
        } else {
            cout << a[i];
        }
        if (i != n) {
            cout << " ";
        }
    }
    return 0;
}