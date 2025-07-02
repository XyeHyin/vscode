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
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    vector<int> nxt0(n, -1), nxt1(n, -1);
    int lst0 = -1, lst1 = -1;
    for (int i = n - 1; i >= 0; i--) {
        nxt0[i] = lst0;
        nxt1[i] = lst1;
        if (s[i] == '0') lst0 = i;
        else lst1 = i;
    }
    vector<int> dp(n, 1e18);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && nxt0[i] != -1)  dp[nxt0[i]] = min(dp[nxt0[i]], dp[i] + x);
        if (s[i] == '0' && nxt1[i] != -1)  dp[nxt1[i]] = min(dp[nxt1[i]], dp[i] + y);
        if (s[i] == '1' && nxt0[i] != -1)  dp[nxt0[i]] = min(dp[nxt0[i]], dp[i] + y);
        if (s[i] == '1' && nxt1[i] != -1)  dp[nxt1[i]] = min(dp[nxt1[i]], dp[i] + x);
        dbg(i); dbg(dp[i]); cout << endl;
    }
    cout << dp[n - 1] << endl;
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