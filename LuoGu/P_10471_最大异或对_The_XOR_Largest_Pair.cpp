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
const int N = 1e5 + 10;
int n, a[N];
int ch[N * 31][2], idx;
void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int j = (x >> i) & 1;
        if (!ch[p][j]) ch[p][j] = ++idx;
        p = ch[p][j];
    }
}
int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        int j = (x >> i) & 1;
        if (ch[p][!j]) res += (1 << i), p = ch[p][!j];
        else p = ch[p][j];
    }
    return res;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], insert(a[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, query(a[i]));
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