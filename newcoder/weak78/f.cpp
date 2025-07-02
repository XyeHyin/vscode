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
    int n;
    cin>>n;
    string s;
    cin>>s;
    s+=s;
    vector<int> cnt(n, 0);
    int ans = 0;
    for (int i = 0; i < n;i++){
        for (int len = 2; len <= n;len++){
            string tmp=s.substr(i, len);
            int cnt = 0;
            for(auto it:tmp){
                if(it=='0')cnt++;
                else ans += cnt;
            }
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