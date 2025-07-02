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
    vector<int> a(n+1);
    arrin(a,n);
    deque<PII> q;
    for(int i = 1; i <= n; i++){
        while(!q.empty() && q.back().first <= a[i]){
            q.pop_back();
        }
        q.push_back(MP(a[i],i));
        while(!q.empty() && q.front().second <= i - k){
            q.pop_front();
        }
        if(i >= k){
            cout << q.front().first << endl;
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