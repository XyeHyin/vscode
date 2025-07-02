// name: P3384.cpp
// date 2025-05-22
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
const int maxn = 1e6;
int n, m, r, p;
#define lc u << 1
#define rc u << 1 | 1
vector<int> e[maxn];
int fa[maxn], dep[maxn], sz[maxn], son[maxn];
int top[maxn], id[maxn], nw[maxn], w[maxn];
int cnt;
struct tree {
    int l, r;
    int lzy_add, sum;
} tr[maxn << 2];
void pushup(int u) { tr[u].sum = tr[lc].sum + tr[rc].sum; }
void pushdown(int u) {
    if (tr[u].lzy_add) {
        tr[lc].sum += tr[u].lzy_add * (tr[lc].r - tr[lc].l + 1);
        tr[rc].sum += tr[u].lzy_add * (tr[rc].r - tr[rc].l + 1);
        tr[lc].lzy_add += tr[u].lzy_add;
        tr[rc].lzy_add += tr[u].lzy_add;
        tr[u].lzy_add = 0;
    }
}
void build(int u, int l, int r) {
    tr[u] = {l, r, 0, nw[r]};
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(u);
}
void dfs1(int u, int p) {
    fa[u] = p, dep[u] = dep[p] + 1, sz[u] = 1;
    for (auto i : e[u]) {
        if (i == p)
            continue;
        dfs1(i, u);
        sz[u] += sz[i];
        if (sz[son[u]] < sz[i])
            son[u] = i;
    }
}
void dfs2(int u, int t) {
    top[u] = t, id[u] = ++cnt, nw[cnt] = w[u];
    if (!son[u])
        return;
    dfs2(son[u], t);
    for (auto i : e[u]) {
        if (i == fa[u] || i == son[u])
            continue;
        dfs2(i, i);
    }
}
int query(int u, int l, int r) {
    if (l <= tr[u].l && r >= tr[u].r)
        return tr[u].sum;
    pushdown(u);
    int ans = 0, mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)
        ans += query(lc, l, r);
    if (r > mid)
        ans += query(rc, l, r);
    return ans;
}
int qpath(int x, int y) {
    int ans = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        ans += query(1, id[top[x]], id[x]);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    ans += query(1, id[x], id[y]);
    return ans;
}
void update(int u, int l, int r, int k) {
    if (l <= tr[u].l && r >= tr[u].r) {
        tr[u].lzy_add += k;
        tr[u].sum += k * (tr[u].r - tr[u].l + 1);
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)
        update(lc, l, r, k);
    if (r > mid)
        update(rc, l, r, k);
    pushup(u);
}
void upath(int x, int y, int k) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        update(1, id[top[x]], id[x], k);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    update(1, id[x], id[y], k);
}
void solve() {
    cin >> n >> m >> r >> p;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        e[x].PB(y);
        e[y].PB(x);
    }
    cnt = 0;
    dfs1(r, 0);
    dfs2(r, r);
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y, z;
            cin >> x >> y >> z;
            upath(x, y, z);
        } else if (op == 2) {
            int x, y;
            cin >> x >> y;
            cout << qpath(x, y) % p << endl;
        } else if (op == 3) {
            int x, z;
            cin >> x >> z;
            update(1, id[x], id[x] + sz[x] - 1, z);
        } else {
            int x;
            cin >> x;
            cout << query(1, id[x], id[x] + sz[x] - 1) % p << endl;
        }
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