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
    int n, x;
    cin >> n >> x;
    vector<int> a(n+1, 0);
    vector<int> pre(n+1, 0);
    vector<int> minpre(n+1, 0);
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i-1] + (x-a[i]);
        minpre[i] = min(minpre[i-1], pre[i]);
        cnt+=a[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans,pre[i] - minpre[i-1]);
    }
    cout << ans + cnt << endl;
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