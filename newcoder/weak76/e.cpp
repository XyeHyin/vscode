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
#define arrout(a, n) rep(i, 1, n) std::cout << a[i] << ' '
#define arrin(a, n) rep(i, 1, n) std::cin >> a[i]
#define endl '\n'

int check(int m, int k) {
    if (k == 0)
        return 1;
    int res = 1;
    while (k > 0) {
        if (k & 1) {
            if (res > 1e18 / m) return 1e18;
            res *= m;
        }
        k >>= 1;
        if (k > 0) {
            if (m > 1e18 / m) return 1e18;
            m *= m;
        }
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 0) {
        cout << 1 << endl;
        return;
    }
    if (k == 1) {
        cout << n << endl;
        return;
    }
    int l = 1, r = 1;
    while (check(r, k) < n) r *= 2;
    int m = 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int tmp = check(mid, k);
        if (tmp == n) {
            m = mid;
            break;
        }
        if (tmp < n) {
            m = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (abs(n - check(m, k)) > abs(n - check(m+1, k))) m = m + 1;
    cout << m << endl;
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