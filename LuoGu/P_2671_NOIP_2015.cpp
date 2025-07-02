#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define PII pair<int, int>
#define dbg(x) std::cout << #x << ":" << x << " "
#define MP make_pair
#define PB push_back
#define rep(i,x,n) for(int i=x;i<=n;i++)
#define dep(i,x,n) for(int i=x;i>=n;i--)
#define arrout(a,n) rep(i,1,n)std::cout<<a[i]
#define arrin(a,n) rep(i,1,n)std::cin>>a[i]
#define endl '\n'
const int mod = 10007;
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    map<int,vector<PII>> cji;
    map<int,vector<PII>> cou;
    map<int, tuple<int,int,int>> cji1;
    map<int, tuple<int,int,int>> cou1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int color;
        cin >> color;
        // dbg(i) << endl;
        if(i&1){
            int len = cji[color].size();
            auto &[xx,yy,zz] = cji1[color];
            ans = (ans+(yy + len * i * a[i] + i * zz + xx * a[i])%mod) % mod;
            // dbg(xx) << endl;
            // dbg(yy) << endl;
            // dbg(zz) << endl;
            xx = (xx + i) % mod;
            yy = (yy + i*a[i]) % mod;
            zz = (zz + a[i]) % mod;
            cji[color].push_back({i,a[i]});
        }else{
            int len = cou[color].size();
            auto &[xx,yy,zz] = cou1[color];
            ans =(ans + (yy + len * i * a[i] + i * zz + xx * a[i]) % mod) % mod;
            // dbg(xx) << endl;
            // dbg(yy) << endl;
            // dbg(zz) << endl;
            xx = (xx + i) % mod;
            yy = (yy + i*a[i]) % mod;
            zz = (zz + a[i]) % mod;
            cou[color].push_back({i,a[i]});
        }
        // dbg(ans) << endl;
    }
    cout << ans%mod << endl;
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