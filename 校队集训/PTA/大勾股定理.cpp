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
    cin>>n;
    for (int i = 1;; i++) {
        int tmpa = 0, tmpb = 0;
        for (int j = i;j<=i+n;j++) {
            tmpa += j*j;
        }
        for(int j = i+n+1;j<=i+2*n;j++){
            tmpb += j*j;
        }
        if (tmpa == tmpb) {
            for(int j = i;j<=i+n;j++){
                cout<<j<<"^2";
                if (j != i+n) cout << " + ";
            }
            cout <<  " ="<<endl;
            for(int j = i+n+1;j<=i+2*n;j++){
                cout<<j<<"^2";
                if (j != i+2*n) cout << " + ";
            }
            cout << endl;
            return;
        }
    }
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