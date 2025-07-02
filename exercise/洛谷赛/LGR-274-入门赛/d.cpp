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
    vector<int> a(n + 1);
    arrin(a, n);
    int cnt = 0;
    rep(i,1,n) {
        int tmp=a[i];
        bool ok = 0;
        rep(j,i+1,n) {
            if(a[j]>=tmp) {
                ok = 1;
                break;
            }
        }
        if(!ok||i==n) {
            cnt++;
        }
    }
    cout << cnt << endl;
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