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
    priority_queue<int> q;
    for (int i = 1; i <= 2*n;i++){
        int x;
        cin >> x;
        q.push(x);
    }
    int ans = 0;
    while(q.size()){
        int x = q.top();
        q.pop();
        if(q.empty()){
            ans += x;
            break;
        }
        int y = q.top();
        q.pop();
        ans += abs(x - y);
    }
    cout << ans << endl;
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