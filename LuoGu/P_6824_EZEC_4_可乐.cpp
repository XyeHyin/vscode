// name: P_6824_EZEC_4_可乐.cpp
// date 2025-05-18
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

#define itn int
#define int long long
#define double long double
#define PII pair<int, int>
#define ff first
#define ss second
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define dbg(x) std::cout << #x << ":" << x << " "
#define dbgl(x) std::cout << #x << ":" << x << "\n"
#define all(x) x.begin(), x.end()
#define MP make_pair
#define PB push_back
#define rep(i, x, n) for (int i = x; i <= n; i++)
#define dep(i, x, n) for (int i = x; i >= n; i--)
#define arrout(a, n) rep(i, 1, n) std::cout << a[i]
#define arrin(a, n) rep(i, 1, n) std::cin >> a[i]
#define endl '\n'
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
    int n, k;
    cin >> n >> k;
    int maxx = -1, pos;
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }
    for (int i = 1; i <= n; i++) {
        int len = log2(a[i]);
        int len2 = log2(k);
        int tmp = len > len2 ? ((~(((1ULL << len2)) - 1)) & a[i]) : 0;
        // dbg(tmp);
        int nn = 0;
        int tmpp = 0;
        for (itn j = len2; j >= 0; j--) {
            int aa = !(((1LL << j) & a[i]) ^ ((1LL << j) & k));
            // dbg(aa);
            if (k & (1LL << j)) {
                if (j == 0) {
                    int l = tmp + tmpp;
                    int r = tmp + tmpp + 1;
                    mp[l]++;
                    mp[r + 1]--;
                    // dbg(l);
                    // dbg(r) << endl;
                    // cout << "ok" << endl;
                    continue;
                }
                int l = tmp + tmpp + (aa ? (1LL << j) : 0);
                int r = l + (1LL << (j)) - 1;
                mp[l]++;
                mp[r + 1]--;
                // dbg(l);
                // dbg(r) << endl;
            } else {
                if (j == 0) {
                    int l = tmp + tmpp;
                    int r = tmp + tmpp;
                    mp[l]++;
                    mp[r + 1]--;
                    // dbg(l);
                    // dbg(r) << endl;
                    continue;
                }
            }
            tmpp += aa ? 0 : (1LL << j);
        }
        // cout << endl;
    }
    int ans = 0, now = 0;
    for (auto it : mp) {
        now += it.ss;
        ans = max(ans, now);
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