// name: P_1833_樱花.cpp
// date 2025-06-10
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
struct XyeHyin {
    int t, c, p;
};
void solve() {
    int sh, sm, eh, em;
    scanf("%lld:%lld %lld:%lld", &sh, &sm, &eh, &em);
    int start = sh * 60 + sm;
    int end = eh * 60 + em;
    int time = end - start;
    if (time < 0) {
        time += 24 * 60;
    }
    int n;
    cin >> n;
    vector<XyeHyin> flowers(n);
    vector<int> vv(N), ww(N);
    bool flag[N] = {false};
    int cnt = 1;
    vector<int> dp(time + 1, 0);
    for (int i = 0; i < n; i++) {
        int t, c, p;
        cin >> t >> c >> p;
        flowers[i] = {t, c, p};
        if (p != 0) {
            for (int j = 1; j <= p; j <<= 1) {
                vv[cnt] = t * j;
                ww[cnt++] = c * j;
                p -= j;
            }
            if (p) {
                vv[cnt] = t * p;
                ww[cnt++] = c * p;
            }
            for (int j = time; j >= vv[i]; j--) {
                dp[j] = max(dp[j], dp[j - vv[cnt]] + ww[cnt]);
            }
        } else {
            for (int j = t; j <= time; j++) {
                dp[j] = max(dp[j], dp[j - t] + c);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return;
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}