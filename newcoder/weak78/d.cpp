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
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    // int ans = 0;
    // if(k>0){
    //     int fi=0,la=0;
    //     while(a[fi]<0){
    //         fi++;
    //         ans += a[fi];
    //     }
    //     while(a[n-la-1]<0){
    //         la++;
    //         ans += a[n-la-1];
    //     }
    //     for(int i=fi;i<n-la;i++){
    //         ans += a[i] * k;
    //     }
    // }else if(k==0){
    //     cout << 0 << endl;
    // }else{

    // }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += a[i] * k;
    }
    cout << ans << endl;
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