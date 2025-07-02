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
    int n,x,y;
    cin >> n >> x >> y;
    if((x & y) != y){
        cout << "NO" << endl;
        return;
    }
    if(x < y){
        cout << "NO" << endl;
        return;
    }
    if(n > __builtin_popcount(x)){
        cout << "NO" << endl;
        return;
    }
    if(n == 1){
        if(x == y)
            cout << "YES" << endl << x << endl;
        else
            cout << "NO" << endl;
        return;
    }
    if(n&1){
        for (int i = 1; i < n;i++){
            cout << " " << y << endl;
        }
    }
    return;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)	solve();
    return 0;
}