// name: P_2216_HAOI_2007_理想的正方形.cpp
// date 2025-06-17
// author: XyeHyin

#include <bits/stdc++.h>
//#pragma GCC optimize("O3,Ofast,unroll-loops")

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
#define dbg(x)  std::cout  << #x << ":" << x << " "
#define dbgl(x) std::cout << #x << ":" << x << "\n"
#define all(x) x.begin(), x.end()
#define MP make_pair
#define PB push_back
#define rep(i,x,n) for(int i=x;i<=n;i++)
#define dep(i,x,n) for(int i=x;i>=n;i--)
#define arrout(a,n) rep(i,1,n)std::cout<<a[i]
#define arrin(a,n) rep(i,1,n)std::cin>>a[i]
#define arrin0(a,n) rep(i,0,n-1)std::cin>>a[i]
#define arrout0(a,n) rep(i,0,n-1)std::cout<<a[i]
#define endl "\n"
#define mem(a,x) memset(a,x,sizeof a)
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
const PII d8[8] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
const PII d4[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const PII d3[3] = {{0, 1}, {1, 0}, {0, 1}};
const PII d2[2] = {{0, 1}, {1, 0}};
const double PI = acos(-1);
const double eps = 1e-9;
const int mod1 = 998244353;

void solve(){
    int a,b,n;
    cin>> a >> b >> n;
    int mp[a+1][b+1];
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >> mp[i][j];
        }
    }
    
    vector<vector<PII>> sum(a, vector<PII>(b, {inf,0}));
    for(int i=0;i<a;i++){
        deque<PII> big, small;
        for(int j=0;j<b;j++){
            while(!big.empty() && big.back().ff <= mp[i][j]) big.pop_back();
            while(!small.empty() && small.back().ff >= mp[i][j]) small.pop_back();
            big.push_back({mp[i][j], j});
            small.push_back({mp[i][j], j});
            while(!big.empty() && big.front().ss <= j - n) big.pop_front();
            while(!small.empty() && small.front().ss <= j - n) small.pop_front();
            if(j < n - 1) continue;
            sum[i][j] = {big.front().ff,small.front().ff};
        }
    }
    int ans = INF;
    for(int j=0;j<b;j++){
        deque<PII> big, small;
        for(int i=0;i<a;i++){
            while(!big.empty() && big.back().ff <= sum[i][j].ff) big.pop_back();
            while(!small.empty() && small.back().ff >= sum[i][j].ss) small.pop_back();
            big.push_back({sum[i][j].ff, i});
            small.push_back({sum[i][j].ss, i});
            while(!big.empty() && big.front().ss <= i - n) big.pop_front();
            while(!small.empty() && small.front().ss <= i - n) small.pop_front();
            if(i < n - 1) continue;
            ans = min(ans, big.front().ff - small.front().ff);
        }
    }
    cout << ans << endl;

    return;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)	solve();
    return 0;
}