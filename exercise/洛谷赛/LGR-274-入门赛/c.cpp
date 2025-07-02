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
    int ans = 0,maxx = -1;
    for (int i = 1; i <= n; i++) {
        int k, d, a;
        int tmp;
        scanf("%lld/%lld/%lld", &k, &d, &a);
        if (k - d >= 0)
            tmp = k * (k - d) + a;
        else if (k >= d)
            tmp = (k - d + 1) * 3 + a;
        else
            tmp = a * 2;
        if (tmp > maxx){
            maxx = tmp;
            ans = i;
        }
    }
    cout << ans << endl;
    return;
}

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}