// name: 小红的区间修改_easy.cpp
// date 2025-06-08
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
const int maxn = 3e5 + 5;
int p = 1e9 + 7; // 998244353;
int a[maxn], w[maxn * 4], lzy_add[maxn * 4], lzy_mul[maxn * 4];
void pushup(const int u) { w[u] = (w[u * 2] + w[u * 2 + 1]) % p; }
void build(const int u, int L, int R) {
    if (L == R) {
        w[u] = a[L];
        return;
    }
    int M = (L + R) / 2;
    build(u * 2, L, M);
    build(u * 2 + 1, M + 1, R);
    pushup(u);
    lzy_mul[u] = 1;
}
bool InRange(int L, int R, int l, int r) { return (l <= L) && (R <= r); }
bool OutofRange(int L, int R, int l, int r) { return (L > r) || (R < l); }
void maketag(int u, int l, int r, int x, int type) {
    if (type == 1) {
        (lzy_add[u] *= x) %= p;
        (lzy_mul[u] *= x) %= p;
        (w[u] *= x) %= p;
    } else {
        (lzy_add[u] += x) %= p;
        (w[u] += x * (r - l + 1)) %= p;
    }
}
void pushdown(int u, int L, int R) {
    int M = (L + R) / 2;
    maketag(u * 2, L, M, lzy_mul[u], 1);
    maketag(u * 2, L, M, lzy_add[u], 2);
    maketag(u * 2 + 1, M + 1, R, lzy_mul[u], 1);
    maketag(u * 2 + 1, M + 1, R, lzy_add[u], 2);
    lzy_mul[u] = 1;
    lzy_add[u] = 0;
}
int query(int u, int L, int R, int l, int r) {
    if (l <= L && R <= r)
        return w[u];
    else if (!OutofRange(L, R, l, r)) {
        int M = (L + R) / 2;
        pushdown(u, L, R);
        return (query(u * 2, L, M, l, r) + query(u * 2 + 1, M + 1, R, l, r)) %
               p;
    } else
        return 0;
}
void update(int u, int L, int R, int l, int r, int x, int type) {
    if (type == 1) {
        if (l <= L && R <= r) {
            maketag(u, L, R, x, 1);
        } else if (!OutofRange(L, R, l, r)) {
            int M = (L + R) / 2;
            pushdown(u, L, R);
            update(u * 2, L, M, l, r, x, 1);
            update(u * 2 + 1, M + 1, R, l, r, x, 1);
            pushup(u);
        }
    } else if (type == 2) {
        if (l <= L && R <= r) {
            maketag(u, L, R, x, 2);
        } else if (!OutofRange(L, R, l, r)) {
            int M = (L + R) / 2;
            pushdown(u, L, R);
            update(u * 2, L, M, l, r, x, 2);
            update(u * 2 + 1, M + 1, R, l, r, x, 2);
            pushup(u);
        }
    }
}
void solve() {
    int q;
    cin >> q;
    int ans = 0;
    build(1, 1, maxn - 1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (query(1, 1, maxn - 1, l, r) == 0) {
            ans = max(ans, r - l + 1);
            update(1, 1, maxn - 1, l, r, 1, 2);
        }
        cout << ans+1 << endl;
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