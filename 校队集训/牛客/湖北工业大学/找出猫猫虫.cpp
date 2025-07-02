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
    int ll = 0, rr = 0;
    int now = 0;
    vector<int> left(n+1), right(n+1);
    for (int i = 1;i<=n;i++){
        int l, r;
        cin >> l >> r;
        left[i] = l;
        right[i] = r;
        ll += l;
        rr += r;
        now += r;
    }   

        if (ll <= 0 && rr >= 0) {
            cout << "YES" << endl;
        } else
            cout << "NO" << endl;
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