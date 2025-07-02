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
const int N = 5e3 + 5;
int fa[N];
int find(int x){
    return fa[x]=fa[x]==x?x:find(fa[x]);
}
void merge(int x, int y){
    int faX = find(x);
    int faY = find(y);
    if(faX == faY) return;
    fa[find(x)] = find(y);
}
struct Edge{
    int u, v, w;
    bool operator < (const Edge &e) const {
        return w > e.w;
    }
};
priority_queue<Edge, vector<Edge>> pq;
int vis[N];
void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        fa[i] = i;
    }
    for (int i = 1; i <= m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        pq.push({u, v, w});
    }
    int ans = 0;
    int cnt = 0;
    while(!pq.empty()){
        auto [u, v, w] = pq.top();
        pq.pop();
        if(find(u)==find(v)) continue;
        merge(u, v);
        ans += w;
        cnt++;
        //cout << u << " " << v <<" "<<w<< endl;
    }
        if(cnt != n - 1){
            cout << "orz" << endl;
            return;
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