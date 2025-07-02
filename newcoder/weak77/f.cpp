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
const int MAXN=1e5+10;
vector<int> adj[MAXN+1];
int g[MAXN + 1],ans[MAXN + 1];
bool vis[MAXN + 1];
int dfs1(int u,int p){
    int sum=vis[u];
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v==p) continue;
        sum+=dfs1(v,u);
    }
    g[u]=sum;
    return sum;
}
void lca(int u,int p){
    ans[u]=g[u]*g[u];
    for(int i=0;i<adj[u].size();i++){
         int v=adj[u][i];
         if(v==p) continue;
         lca(v,u);
         ans[u]-=g[v]*g[v];
    }
}
void solve(){
    int n;
    cin >> n;
    rep(i, 1, n - 1){
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    int k;
    cin >> k;
    for (int i = 0;i<k;i++){
        int x;
        cin >> x;
        vis[x] = 1;
    }
    dfs1(1, -1);
    lca(1, -1);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
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