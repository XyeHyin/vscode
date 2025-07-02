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
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1);
    vector<int> b(m + 1);
    for (int i = 1; i <= m; i++) {
        int aa, bb;
        cin >> aa >> bb;
        if (aa > bb)
            swap(aa, bb);
        a[i] = aa;
        b[i] = bb;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    auto check = [&](int x) {
        int k = n;
        int cnt = a[0], j = 0;
        while (1) {
            k--;
            if (cnt > b[j]) {
                j++;
            }
            cnt += x;
            // dbg(cnt);
            if (cnt > b[j] && j == m) {
                // dbg(b[j]);
                // dbg(cnt);
                break;
            }
            if (cnt > b[j]) {
                if (cnt < a[j + 1]) {
                    cnt = a[j + 1];
                    j++;
                    k--;
                } else {
                    while (cnt > a[j + 1])
                        j++;
                }
            }

            if (k <= 0) {
                return 1;
            }
        }
        return 0;
    };
    int l = 0, r = b[m], ans, mid;
    while (l <= r) {
        if (check(mid = l + r >> 1)) {
            ans = mid, l = mid + 1;
        } else {
            r = mid - 1;
        }
        // dbg(mid);
    }
    cout << ans << endl;
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