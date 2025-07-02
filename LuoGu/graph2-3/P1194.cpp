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
const int maxn = 505;
int fa[maxn];
int find(int x){
    return fa[x] = fa[x] == x ? x : find(fa[x]);
}
void merge(int x, int y){
    int faX = find(x);
    int faY = find(y);
    if(faX == faY) return;
    fa[find(x)] = find(y);
}
struct Edge{
    int w, u, v;
    bool operator < (const Edge &e) const {
        return w > e.w;
    }
};
void solve(){
    int a, b;
    cin >> a >> b;
    priority_queue<Edge> pq;
    for (int i = 1; i <= b; i++){
        fa[i] = i;
    }
    for (int i = 1; i <= b; i++){
        pq.push({a, 0, i});
    }
    for (int i = 1; i <= b; i++){
        for(int j = 1; j <= b; j++){
            int w;
            cin >> w;
            if(i==0) pq.push({a, i, j});
            if (w != 0){
                pq.push({w, i, j});
            }
        }
    }
    int ans = 0;
    while(!pq.empty()){
        auto [w, u, v] = pq.top();
        pq.pop();
        if (find(u) == find(v)) continue;
        merge(u, v);
        ans+= w;
        //cout << u << " " << v <<" "<<w<< endl;
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