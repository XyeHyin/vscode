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
    vector<int> a(n + 1, 0);
    arrin(a, n);
    vector<int> aa = a;
    sort(aa.begin() + 1, aa.end(), greater<int>());
    vector<int> b(n + 1, 0);
    b[n/2+1] = aa[1];
    for (int i = 1; i <= (n + 1) / 2; i++) {
        b[n/2+1-i] = aa[2 * i];
        if (n/2+1+i <= n) {
            b[n/2+1+i] = aa[2 * i + 1];
        }
    }
    // for(int i = 1; i <= n; i++){
    //     cout << b[i] << " ";
    // }
    double ans = 0.0;
    for (int i = 1; i < n; i++) {
        ans += (b[i] + b[i + 1]) / 2.0;
    }
    ans = round(ans * 100) / 100;
    cout << fixed << setprecision(2) << ans << endl;

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