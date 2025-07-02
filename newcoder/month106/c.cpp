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
void solve() {
    int n;
    cin >> n;
    int a[505][505];
    rep(i,0,n+1) a[0][i] = a[n + 1][i] = a[i][0] = a[i][n + 1] = 0;
    rep(i, 1, n) rep(j, 1, n) cin >> a[i][j];
    bool OK1 = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
                if (a[i][j]>0) if(a[i-1][j]>0 || a[i+1][j]>0 || a[i][j-1]>0 || a[i][j+1]>0) OK1 = 0;
                if (a[i][j]<0) if(a[i-1][j]<0 || a[i+1][j]<0 || a[i][j-1]<0 || a[i][j+1]<0) OK1 = 0;
        }
    }
    if (OK1)  cout << "YES" << endl;
    else cout << "NO" << endl;
    return ;
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
