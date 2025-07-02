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

void solve(){
    int n, m;
    cin>>n>>m;
    vector<string> a(n); 
    for(int i=0;i<n;i++) cin>>a[i];
    unordered_map<string,int> mp;
    for (int i = 0; i < m;i++){
        string s;
        for(int j=0;j<n;j++){
            if(a[j][i]=='1') s += '0';
            else s += '1';
        }
        mp[s]++;
    }
    int ans = 0;
    for(auto x:mp){
        ans = max(ans, x.second);
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