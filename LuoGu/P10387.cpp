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
struct XyeHyin{
    int p, c;
};
void solve(){
    int n, s;
    cin >> n >> s;
    vector<XyeHyin> a(n+1);
    int len = 0;
    int all = 0;
    int alll = 0;
    map<int, unordered_set<int>> mp;
    for(int i = 1; i <= n; i++){
        cin >> a[i].p >> a[i].c;
        len = max(len, a[i].c);
        all += a[i].p;
        alll += a[i].p * a[i].c;
        mp[a[i].c].insert(a[i].p);
    }
    vector<int> dp(len+1, 0);
    dp[0] = alll;
    int ans = alll;
    for(int i = 1; i <= len; i++){
        dp[i] = dp[i - 1] - all + s;
        if(mp[i].size() > 0){
            for(auto it = mp[i].begin(); it != mp[i].end(); it++){
                all -= *it;
            }
        }
        // dbg(dp[i]) << endl;
        ans = min(ans, dp[i]);
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