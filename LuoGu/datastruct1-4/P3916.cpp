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
vector<vector<int>> adj;
int n, m;
int maxx = -1;
void dfs(int u) {
    for(int i=1; i<=n; i++){
        if(adj[u][i] == 1){
            maxx = max(maxx, i);
            dfs(i);
        }
    }
}
void solve(){
    cin>>n>>m;
    adj.resize(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=m; i++){
        int u, v;
        cin>>u>>v;
        adj[u][v] = 1;
    }
    for(int i=1; i<=n; i++){
        maxx = i;
        dfs(i);
        cout<<maxx<<" ";    
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