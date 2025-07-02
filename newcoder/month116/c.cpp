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
int rangeBitwiseAnd(int m, int n) {
    int shift = 0;
    while (m < n) {
        m >>= 1;
        n >>= 1;
        ++shift;
    }
    return m << shift;
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        if(r-l>60){
            cout << 0 << endl;
            continue;
        }
        vector<int> b(a.begin() + l - 1, a.begin() + r);
        int ans = b[0];
        for (int i = 1; i < b.size(); i++) {
            ans = ans + b[i] - (b[i] ^ ans);
        }
        cout << ans << endl;
    }
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
