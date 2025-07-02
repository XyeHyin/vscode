#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;

    int zero_groups = 0;
    bool in_zero_group = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (!in_zero_group) {
                zero_groups++;
                in_zero_group = true;
            }
        } else {
            in_zero_group = false;
        }
    }

    if (zero_groups == 0) {
        cout << 0 << endl;
        return;
    }

    int ans = (zero_groups - 1) * min(x, y) + y;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}