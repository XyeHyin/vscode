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
signed solve(){
    int n, k;
    cin >> n >> k;
    int idx = max(log2(n), log2(k));
    int cnt = 0;
    for (int i = idx; i > 0; i--) {
        int nn = (n >> i) & 1;
        int kk = (k >> i) & 1;
        if (!nn && kk)
            cnt++;
        else if (nn && !kk)
            return -1;
    }
    return cnt;
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