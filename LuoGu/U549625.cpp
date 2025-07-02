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
    cin >> n;
    vector<int> pre(n+1, 0);
    vector<int> suf(n+2, 0);
    vector<int> minpre(n+1, 0);
    vector<int> maxsuf(n+2, 0);
    vector<int> a(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
        minpre[i] = min(minpre[i-1], pre[i]);
    }
    for(int i = n; i >= 1; i--){
        suf[i] = suf[i+1] + a[i];
        maxsuf[i] = min(maxsuf[i+1], suf[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans=(pre[i] - minpre[i-1])+(suf[i+1]-maxsuf[i+1]);
        cout << ans << " ";
    }
    cout<<endl;
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