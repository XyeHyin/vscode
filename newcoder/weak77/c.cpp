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
int x, y, a, b, c, d;
int dx[4] = {0, 0, -c, d};
int dy[4] = {a, -b, 0, 0};

void solve() {
    cin >> x >> y >> a >> b >> c >> d;
    if (x % __gcd(c,d) == 0 && y % __gcd(a,b) == 0) cout << "YES" << endl;
    else  cout << "NO" << endl;
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