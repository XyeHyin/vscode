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
    int n, m, k;
    cin >> n >> m >> k;
    if(k<max(n,m)){
        cout<<-1<<endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i<j){

            if(i==n-1&&j!=m-1&&k){
                cout<<1<<" ";
                k--;
                continue;
            }
            if(i==n-1&&j==m-1){
                cout<<k<<endl;
                return;
            }
            }
            else{
                if(j==m-1&&i!=n-1&&k){
                    cout<<1<<" ";
                    k--;
                    continue;
                }
                if(i==n-1&&j==m-1){
                    cout<<k<<endl;
                    return;
                }
            }
            if(k>min(n-i,m-j)&&i==j){
                cout<<1<<" ";
                k--;
                continue;
            }
            cout<<0<<" ";
        }
        cout<<endl;
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