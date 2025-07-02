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
int toDecimal(string s) {
    int num = 0;
    for (char c : s) {
        num = (num << 1) | (c - '0');
    }
    return num;
}
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    string dic = "";
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        dic += s;
    }
    int dicc = toDecimal(dic);
    vector<int> a(q);
    for (int i = 0; i < q; i++) {
        string tmp = "";
        for (int j = 0; j < n; j++) {
            string s;
            cin >> s;
            tmp += s;
        }
        a[i] = toDecimal(tmp);
    }
    int minn = LLONG_MAX;
    string ans = "";
    int mp = (1LL << (n * m)) - 1;
    int nd = (~dicc) & mp;
    if (nd == 0) {
        cout << 0 << endl;
        cout << endl;
        return;
    }
    for (int l = 1; l < (1 << q); l++) {
        int tmp = 0;
        int cnt = __builtin_popcount(l);
        for (int j = 0; j < q; j++) {
            if (l & (1 << j)) {
                tmp |= a[j];
            }
        }
        if ((tmp & dicc)) continue;
        if ((tmp & nd) != nd) continue;
        if (cnt < minn) {
            minn = cnt;
            ans = "";
            for (int j = 0; j < q; j++) {
                if (l & (1 << j)) {
                    ans += to_string(j + 1) + " ";
                }
            }
        }
    }
    if (minn == LLONG_MAX) cout << -1 << endl;
    else {
        cout << minn << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
        }
        cout << endl;
    }
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