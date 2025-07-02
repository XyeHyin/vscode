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
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans = 0;
    for (int i = 0;i<k-1;i++){
        ans+=abs(s[i]-s[i+1]);
    }
    int tmp = ans;
    for (int i = 0;i<=n-k;i++){
        tmp = tmp - abs(s[i-1]-s[i]) + abs(s[i+k-2]-s[i+k-1]);
        ans += tmp;
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