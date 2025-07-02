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
int n,m,s;
const int maxn = 1e5+5;
vector<PII> edge[maxn];
vector<int> vis(maxn,0),dis(maxn,0x3f3f3f3f);
priority_queue<PII,vector<PII>,greater<PII>> q;
void dij(int x){
    dis[x] = 0;
    q.push({0,x});
    while(!q.empty()){
        auto [d,u] = q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for( auto [a,b] : edge[u]){
            if(dis[a]>dis[u]+b){
                dis[a] = dis[u]+b;
                q.push({dis[a],a});
            }
        }
    }
}
void solve(){
    cin >> n >> m >> s;
    for(int i=1;i<=m;i++){
        int u,v,d;
        cin >> u >> v >> d;
        edge[u].PB({v,d});
    }
    dij(s);
    for(int i=1;i<=n;i++){
        cout << dis[i] << " ";
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