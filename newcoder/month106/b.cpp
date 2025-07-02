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
#define endl "\n"
void solve() {
    int n,cnt;
    vector<int> a[505];
    cin >> n;
    cnt = n;
    rep(i, 1, n) {
        a[i].PB(i);
        rep(j,i+1,n) {
            cnt++;
            a[i].PB(cnt);
            a[j].PB(cnt);
        }
    }
    rep(i, 1, n) rep(j, 0, n - 1)  cout << a[i][j] << " \n"[j == n - 1];
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