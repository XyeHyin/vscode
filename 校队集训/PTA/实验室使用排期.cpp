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
struct XyeHyin {
    string be, en;
};
void solve() {
    int n;
    cin >> n;
    vector<XyeHyin> a;
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        a.push_back({s1, s2});
    }
    sort(a.begin(), a.end(), [&](XyeHyin aa, XyeHyin bb) {
        if (aa.en == bb.en)
            return aa.be > bb.be;
        return aa.en < bb.en;
    });
    for(int i = 0; i < n; i++) {
        cout << a[i].be << " " << a[i].en << endl;
    }
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (a[i].be <= a[i - 1].en) cnt++;
        else {
            a[i].be = a[i - 1].be;
            a[i].en = a[i - 1].en;
        }
    }
    cout << cnt << endl;
    return;
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}