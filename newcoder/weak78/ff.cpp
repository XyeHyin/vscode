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
const int MOD = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += s;
    vector<int> pre(2 * n + 1, 0);
    for (int i = 0; i < 2 * n; i++) {
        pre[i + 1] = pre[i] + s[i] == '0';
    }
    int anss = 0;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n; i++) {
            int j = i + len;
            if(j>2*n) break;
            int cnt = 0, ans = 0;
            for (int k = i; k < j;k++){
                if(s[k]=='0') cnt++;
                else ans += cnt;
            }
            anss = (anss + ans) % MOD;
        }
    }

    cout << anss << endl;
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