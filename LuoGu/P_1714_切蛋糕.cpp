// name: P_1714_切蛋糕.cpp
// date 2025-06-17
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
template <typename T> class SparseTable {
    using VT = std::vector<T>;
    using VVT = std::vector<VT>;
    using func_type = std::function<T(const T &, const T &)>;

    VVT ST;
    func_type op;

    static T default_func(const T &t1, const T &t2) { return std::max(t1, t2); }

  public:
    // 构造函数，v为原始数组，_func为可选的合并函数
    SparseTable(const std::vector<T> &v, func_type _func = default_func) {
        op = _func;
        int len = v.size(), l1 = std::ceil(std::log2(len)) + 1;
        ST.assign(len, VT(l1, 0));
        for (int i = 0; i < len; ++i) {
            ST[i][0] = v[i];
        }
        for (int j = 1; j < l1; ++j) {
            int pj = (1 << (j - 1));
            for (int i = 0; i + pj < len; ++i) {
                ST[i][j] = op(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    // 查询区间 [l, r] 的合并结果
    T query(int l, int r) const {
        int lt = r - l + 1;
        int q = std::floor(std::log2(lt));
        return op(ST[l][q], ST[r - (1 << q) + 1][q]);
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> pre(n + 1, 0);
    vector<int> tmp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    int ans = -INF;
    // for (int r = m; r <= n; r++) {
    //     int minn = INF;
    //     for (int l = r - m; l < r; l++) {
    //         minn = min(minn, pre[l]);
    //     }
    //     ans = max(ans, pre[r] - minn);
    // }
    deque<int> dq;
    for (int r = 1; r <= n; r++) {
        while (!dq.empty() && pre[r - 1] <= pre[dq.back()]) dq.pop_back();
        dq.push_back(r - 1);
        while (!dq.empty() && dq.front() < r - m) dq.pop_front();
        ans = max(ans, pre[r] - pre[dq.front()]);
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