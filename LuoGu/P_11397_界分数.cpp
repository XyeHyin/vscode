#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
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
const int mod = 998244353;
void solve() {
    int n;
    cin >> n;
    int cnt = 1;
    int j=1;
    for (int i = 2; i <= n; i+=j) {
        cnt = (cnt + (((int)ceil(log2(i))%mod) + 1)*j%mod) % mod;
        j *= 2;
    }
    int len=log2(n);
    cnt =(cnt+ ((n - (j))%mod) * (int)(ceil(log2(n)) + 1)%mod)%mod;
    cout << cnt%mod << endl;
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