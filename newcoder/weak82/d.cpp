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

void solve() {
    int n;
    cin >> n;
    int ans = 1;
    int flag = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int x = a[i];
        if (x != flag) {
            flag = x;
        } else {
            if (x > flag&&i) {
                cout << 0 << endl;
                return;
            }
            int tmp = n - x - i + 1;
            if (tmp <= 0) {
                cout << 0 << endl;
                return;
            }
            ans = ans * tmp % 998244353;
        }
        if (i == n - 1 && x != 1) {
            cout << 0 << endl;
            return;
        }
    }
    cout << ans << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}