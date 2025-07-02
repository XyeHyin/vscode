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
int k;
vector<int> a;
bool check(int n) {
    int ans = 0;
    rep(i, 0, a.size() - 1)  ans +=static_cast<int>(a[i] *1.0/n +0.999999999999);
    dbg(n) << " ";
    dbg(ans) << endl;
    return ans <= k;
}
void solve() {
    int n;
    cin >> n;
    a.resize(n);
    cin >> k;
    rep(i, 0, n - 1) cin >> a[i];
    int l = 0, r = 1e7;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (!check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    cout << l << endl;
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