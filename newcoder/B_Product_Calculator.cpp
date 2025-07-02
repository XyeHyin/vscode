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
    cin >> n >> k;
    int ans = 1;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        string s = to_string(x);
        if(s.size()+to_string(ans).size() > k+1){
            ans = 1;
            continue;
        }
        ans *= x;
        if(to_string(ans).size() > k){
            ans = 1;
        }
    }
    cout<<ans<<endl;
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