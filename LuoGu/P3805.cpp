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
const int N = 3e7;
int d[N];
void get_d(string s, int n) {
    d[1] = 1;
    for (int i = 2, l = 1, r = 1; i <= n; i++) {
        if (i <= r)
            d[i] = min(r - i + 1, d[l + r - i]);
        while (s[i - d[i]] == s[i + d[i]])
            d[i]++;
        if (i + d[i] - 1 > r)
            l = i - d[i] + 1, r = i + d[i] - 1;
    }
}
void solve() {
    string s;
    string ss(N, 0);
    cin >> s;
    s = " " + s;
    int n = s.size(), k = 0;
    ss[0] = '$';
    ss[++k] = '#';
    for (int i = 1; i <= n; i++) {
        ss[++k] = s[i];
        ss[++k] = '#';
    }
    n = k;
    get_d(ss, n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, d[i] - 1);
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