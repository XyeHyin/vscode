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
    vector<int> med(n, 0);
    for(int i = 0; i < n; i++){
        cin >> med[i];
    }
    vector<vector<PII>> edge(n + 1);
    vector<int> dis(n + 1, 0x3f3f3f3f), cnt(n + 1, 0), vis(n + 1, 0);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    int a, b, c;
    while (cin >> a >> b >> c) {
        
    }
    auto dij = [&](int x) {
        cnt[1] = 1;
        dis[x] = 0;
        q.push({0, x});
        while (!q.empty()) {
            auto [d, u] = q.top();
            q.pop();
            if (vis[u])
                continue;
            vis[u] = 1;
            for (auto [a, b] : edge[u]) {
                if (dis[a] > dis[u] + b) {
                    dis[a] = dis[u] + b;
                    cnt[a] = cnt[u];
                    q.push({dis[a], a});
                } else if (dis[a] == dis[u] + b) {
                    cnt[a] = (cnt[u] + cnt[a]);
                }
            }
        }
    };
    dij(1);
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