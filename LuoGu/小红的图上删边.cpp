// name: 小红的图上删边.cpp
// date 2025-06-12
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
int fa[N];
int find(int x) { return fa[x] = fa[x] == x ? x : find(fa[x]); }
void merge(int x, int y) {
    int faX = find(x);
    int faY = find(y);
    if (faX == faY)
        return;
    fa[find(x)] = find(y);
}
struct Edge {
    int u, v, w;
    bool operator<(const Edge &e) const { return w > e.w; }
};
priority_queue<Edge, vector<Edge>> pq;
int vis[N];
int callast0(int a,int b) {
    int ans = 0;
    int cnt2 = 0,cnt5 = 0;
    while(a%2==0){
        a /= 2;
        cnt2++;
    }
    while(a%5==0){
        a /= 5;
        cnt5++;
    }
    while(b%2==0){
        b /= 2;
        cnt2++;
    }
    while(b%5==0){
        b /= 5;
        cnt5++;
    }
    ans += min(cnt2, cnt5);
    return ans;
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    arrin(a, n);
    vector<Edge> e(n + 1);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    int tmp = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        e.PB({u, v, callast0(a[u],a[v])});
        pq.push({u, v, callast0(a[u],a[v])});
        tmp += callast0(a[u],a[v]);
    }
    int ans = 0;
    while (!pq.empty()) {
        auto [u, v, w] = pq.top();
        pq.pop();
        if (find(u) == find(v))
            continue;
        merge(u, v);
        ans += w;
    }
    cout << tmp - ans << endl;
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