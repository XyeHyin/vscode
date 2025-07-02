#include <bits/stdc++.h>
using namespace std;

#define int long long
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
    vector<int> pre(n + 1, 0);
    int cnt0 = 0, cnt1 = 0;
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0')cnt0++;
        else cnt1++;
        pre[i] = ((cnt0%2)*2)+(cnt1%2);
    }
    vector<int> flag(4, 0);
    for (int i = 0; i <= n; i++) {
        flag[pre[i]] = max(flag[pre[i]],i);
    }
    int OK = 0;
    for (int l = 1; l < n; l++) {
        if (flag[pre[l]] > l)  OK++;
    }
    double ans = OK*1.0 / n;
    printf("%.10lf\n", ans);
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