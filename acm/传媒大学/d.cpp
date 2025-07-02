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
int gcd(int a, int b) {
    while (b ^= a ^= b ^= a %= b);
    return a;
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    int d=gcd(a[1], a[n]);
    if(d==1){
        cout<<"1"<<endl;
        cout<<1<<" "<<n<<endl;
        return;
    }else{
        for(int i = 2; i < n; i++){
            if(a[i]==1){
                cout<<"2"<<endl;
                cout<<1<<" "<<i<<" "<<n<<endl;
                return;
            }
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