// name: P_4195_模板_扩展_BSGS_exBSGS.cpp
// date 2025-06-25
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
int gcd(int a, int b) {
    while (b ^= a ^= b ^= a %= b)
        ;
    return a;
}
long long fastPow(long long base, long long power, long long mod) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        power >>= 1;
    }
    return result;
}
void solve() {
    while (1) {

        int a, p, b, tmpp, k, m, tmp;
        unordered_map<int, int> mp;
        cin >> a >> p >> b;
        if (a == 0 && b == 0 && p == 0)
            break;
        a %= p, b %= p;
        if (b == 1 || p == 1) {
            cout << 0 << endl;
            goto end;
        }
        tmpp = 1, k = 0;
        while (gcd(a, p) != 1) {
            int d = gcd(a, p);
            if (b % d) {
                cout << "No Solution" << endl;
                goto end;
            }
            p /= d;
            b /= d;
            tmpp = (tmpp * (a / d)) % p;
            k++;
            if (tmpp == b) {
                cout << k << endl;
                goto end;
            }
        }

        m = ceil(sqrt(p));
        
        mp[b] = 0;
        tmp = b;
        for (int i = 1; i < m; i++) {
            tmp = (tmp * a) % p;
            mp[tmp] = i;
        }
        for (int i = 1; i <= m; i++) {
            tmp = fastPow(a, i * m, p) * tmpp % p;
            if (mp.count(tmp)) {
                cout << i * m - mp[tmp] + k << endl;
                goto end;
            }
        }
        cout << "No Solution" << endl;
    end:;
    }
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int a;
    solve();
    return 0;
}