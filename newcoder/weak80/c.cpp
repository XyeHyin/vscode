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
    string s;
    cin >> s;
    vector<int> pre(n+1, 0);
    for(int i = 0; i < n; i++) pre[i+1] = pre[i] + (s[i]=='1' ? 1 : -1);
    vector<int> cnt(n+1, 0);
    cnt[0] = pre[0];
    for(int i = 1; i <= n; i++) cnt[i] = min(cnt[i-1], pre[i]);
    vector<int> cntt(n+1, 0);
    cntt[n] = pre[n];
    for(int i = n-1; i >= 0; i--)cntt[i] = min(pre[i], cntt[i+1]);
    int ans = 0;
    for(int i = 0; i < n; i++){
        bool OK = 1;
        if(i&& cnt[i] < 0) OK = 0;
        if(pre[i] < -1) OK = 0;
        if ((i == n - 1 ? pre[n] : cntt[i + 1]) + (s[i] == '0' ? 2 : 0) < 0) OK = 0;
        if(OK) ans++;
    }
    cout << ans << endl;
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