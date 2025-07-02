// name: 小红的踏前斩.cpp
// date 2025-06-13
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
    vector<int> a(n);
    arrin0(a, n);
    vector<int> b = a;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i < n - 2) {
            while (a[i] >= 1 && a[i + 1] >= 2 && a[i + 2] >= 3) {
                int cnt = min({
                    a[i] / 1, a[i + 1] / 2, a[i + 2] / 3
                });
                ans += cnt * 5;
                a[i] -= cnt * 1;
                a[i + 1] -= cnt * 2;
                a[i + 2] -= cnt * 3;
            }
        }
        if (a[i] <= 0)
            continue;
        ans += a[i];
        a[i] = 0;
    }
    int ans2 = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (i > 1) {
            if (b[i] >= 3 && b[i - 1] >= 2 && b[i - 2] >= 1) {
                int cnt = min({
                    b[i] / 3, b[i - 1] / 2, b[i - 2] / 1
                });
                ans2 += cnt * 5;
                b[i] -= cnt * 3;
                b[i - 1] -= cnt * 2;
                b[i - 2] -= cnt * 1;
            }
        }
        if (b[i] <= 0)
            continue;
        ans2 += b[i];
        b[i] = 0;
    }
    cout << min(ans, ans2) << endl;
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