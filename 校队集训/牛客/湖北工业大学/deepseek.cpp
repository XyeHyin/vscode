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
    int n, q;
    cin>> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> pre(n+1, 0);
    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1] + a[i-1];
    }
    while (q--)
    {
        int x;
        cin>> x;
        auto it = upper_bound(pre.begin()+1, pre.end(), x);
        if(*it>x) it--;
        cout<< it-pre.begin() << endl;
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