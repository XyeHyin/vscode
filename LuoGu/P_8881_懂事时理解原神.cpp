// name: P_8881_懂事时理解原神.cpp
// date 2025-06-27
// author: XyeHyin

#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

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

#pragma region IO 重载 & 工具函数
template <class T1, class T2>
istream &operator>>(istream &cin, pair<T1, T2> &a) {
    return cin >> a.first >> a.second;
}
template <std::size_t Index = 0, typename... Ts>
typename std::enable_if<Index == sizeof...(Ts), void>::type
tuple_read(std::istream &is, std::tuple<Ts...> &t) {}
template <std::size_t Index = 0, typename... Ts>
    typename std::enable_if <
    Index<sizeof...(Ts), void>::type tuple_read(std::istream &is,
                                                std::tuple<Ts...> &t) {
    is >> std::get<Index>(t);
    tuple_read<Index + 1>(is, t);
}
template <typename... Ts>
std::istream &operator>>(std::istream &is, std::tuple<Ts...> &t) {
    tuple_read(is, t);
    return is;
}
template <class T1> istream &operator>>(istream &cin, valarray<T1> &a);
template <class T1> istream &operator>>(istream &cin, vector<T1> &a) {
    for (auto &x : a)
        cin >> x;
    return cin;
}
template <class T1> istream &operator>>(istream &cin, valarray<T1> &a) {
    for (auto &x : a)
        cin >> x;
    return cin;
}
template <class T1, class T2> bool cmin(T1 &x, const T2 &y) {
    if (y < x) {
        x = y;
        return 1;
    }
    return 0;
}
template <class T1, class T2> bool cmax(T1 &x, const T2 &y) {
    if (x < y) {
        x = y;
        return 1;
    }
    return 0;
}
template <class T1> vector<T1> range(T1 l, T1 r, T1 step = 1) {
    assert(step > 0);
    int n = (r - l + step - 1) / step, i;
    vector<T1> res(n);
    for (i = 0; i < n; i++)
        res[i] = l + step * i;
    return res;
}
template <class T1>
basic_string<T1> operator*(const basic_string<T1> &s, int m) {
    auto r = s;
    m *= s.size();
    r.resize(m);
    for (int i = s.size(); i < m; i++)
        r[i] = r[i - s.size()];
    return r;
}
using lll = __int128;
istream &operator>>(istream &cin, lll &x) {
    bool flg = 0;
    x = 0;
    static string s;
    cin >> s;
    if (s[0] == '-')
        flg = 1, s = s.substr(1);
    for (char c : s)
        x = x * 10 + (c - '0');
    if (flg)
        x = -x;
    return cin;
}
ostream &operator<<(ostream &cout, lll x) {
    static char s[60];
    if (x < 0)
        cout << '-', x = -x;
    int tp = 1;
    s[0] = '0' + (x % 10);
    while (x /= 10)
        s[tp++] = '0' + (x % 10);
    while (tp--)
        cout << s[tp];
    return cout;
}
template <class T1, class T2>
ostream &operator<<(ostream &cout, const pair<T1, T2> &a) {
    return cout << a.first << ' ' << a.second;
}
template <class T1, class T2>
ostream &operator<<(ostream &cout, const vector<pair<T1, T2>> &a) {
    for (auto &x : a)
        cout << x << '\n';
    return cout;
}
template <class T1> ostream &operator<<(ostream &cout, vector<T1> a) {
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    return cout;
}
template <class T1> ostream &operator<<(ostream &cout, const valarray<T1> &a) {
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    return cout;
}
template <class T1>
ostream &operator<<(ostream &cout, const vector<valarray<T1>> &a) {
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << '\n' << a[i];
    return cout;
}
template <class T1>
ostream &operator<<(ostream &cout, const vector<vector<T1>> &a) {
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << '\n' << a[i];
    return cout;
}
#define err(...) cerr << format(__VA_ARGS__)
#define errln(...) cerr << format(__VA_ARGS__) << '\n'
template <typename... Args> void print(const Args &...args) {
    ((cout << args << ' '), ...);
    cout << '\n';
}
template <typename... Args> void printn(const Args &...args) {
    (cout << ... << args);
    cout << '\n';
}
#pragma endregion

#define int long long
#define d64 long double
#define PII pair<int, int>
#define ff first
#define ss second
#define itn signed
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
#define coutf(x) cout << fixed << setprecision(x)

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
void dfs(vector<PII> edge[], int u, vector<int> &vis, vector<int> &dis,
         int parent, bool &flag) {
    if (flag)
        return;
    vis[u] = 1;
    for (auto [v, w] : edge[u]) {
        if (vis[v]) {
            if (v != parent) {
                if (dis[v] != dis[u] + 1) {
                    flag = 1;
                    return;
                }
            }
            continue;
        }
        dis[v] = dis[u] + 1;
        dfs(edge, v, vis, dis, u, flag);
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<PII> edge2[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edge2[v].push_back({u, 1});
        edge2[u].push_back({v, 1});
    }
    vector<int> vis2(n + 1, 0);
    vector<int> dis2(n + 1, INF);
    bool flag = 0;
    dfs(edge2, 1, vis2, dis2, 0, flag);
    if (flag) cout << "0.000" << endl;
    else cout << "1.000" << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}