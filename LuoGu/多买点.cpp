// name: 多买点.cpp
// date 2025-06-11
// author: XyeHyin

#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")

// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
// #include "atcoder/maxflow"
// #include "atcoder/mincostflow"
// #include "atcoder/modint"
// #include "atcoder/scc"
// #include "atcoder/segtree"
// #include "atcoder/string"
// #include "atcoder/twosat"
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

#define int long long
#define d64 long double
#define PII pair<int, int>
#define ff first
#define ss second
#define itn int
#define dbg(x) std::cout << #x << ":" << x << " "
#define dbgl(x) std::cout << #x << ":" << x << "\n"
#define all(x) x.begin(), x.end()
#define MP make_pair
#define PB push_back
#define rep(i, x, n) for (int i = x; i <= n; i++)
#define dep(i, x, n) for (int i = x; i >= n; i--)
#define arrout(a, n) rep(i, 1, n) std::cout << a[i]
#define arrin(a, n) rep(i, 1, n) std::cin >> a[i]
#define arrin0(a, n) rep(i, 0, n - 1) std::cin >> a[i]
#define arrout0(a, n) rep(i, 0, n - 1) std::cout << a[i]
#define endl "\n"
#define mem(a, x) memset(a, x, sizeof a)
#define YES() cout << "YES" << endl
#define NO() cout << "NO" << endl
#define Yes() cout << "Yes" << endl
#define No() cout << "No" << endl
#define yes() cout << "yes" << endl
#define no() cout << "no" << endl

const int mod = 1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e18;
const int inf = 0x3f3f3f3f;
const PII d8[8] = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                   {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
const PII d4[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const PII d3[3] = {{0, 1}, {1, 0}, {0, 1}};
const PII d2[2] = {{0, 1}, {1, 0}};
const double PI = acos(-1);
const double eps = 1e-9;
const int mod1 = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<PII> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].ff >> a[i].ss;
    }
    sort(a.begin(), a.end(), [&](const PII &x, const PII &y) {
        return x.ff < y.ff || (x.ff == y.ff && x.ss < y.ss);
    });
    vector<PII> b;
    for (int i = 0; i < n; i++) {
        if (!b.empty() && a[i].ff == b.back().ff) {
            if (b.back().ss < a[i].ss) {
                b.back().ss = max(b.back().ss, a[i].ss);
            }
        }
        if (b.empty() || a[i].ss > b.back().ss) {
            b.push_back(a[i]);
        }
    }
    int q;
    cin >> q;
    vector<int> c(b.size() + 1, 0);
    for (int i = 0; i < b.size(); i++) {
        if (i)
            c[i] = max(b[i].ss, c[i - 1]);
        else
            c[i] = b[i].ss;
    }
    vector<int> d(c.size() + 1, 0X3F3F3F3F);
    for (int i = b.size() - 1; i >= 0; i--) {
        d[i] = min(b[i].ff - b[i].ss, d[i + 1]);
    }
    while (q--) {
        int x;
        cin >> x;
        auto it = lower_bound(b.begin(), b.end(), MP(x, INF));
        if (it == b.begin()) {
            cout << min(x, d[0]) << endl;
        } else if (it == b.end()) {
            cout << x - c[b.size() - 1] << endl;
        } else {
            cout << min(x - c[it - b.begin() - 1], d[it - b.begin()]) << endl;
        }
    }
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