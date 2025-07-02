#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
vector<pair<int, int>> edge[maxn];
vector<int> dis(maxn, 0x3f3f3f3f), vis(maxn, 0);
vector<int> pre(maxn, -1);
vector<int> a(maxn);
priority_queue <pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> q;
void dij(int s1) {
    dis[s1] = 0;
    q.push({0, s1});
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : edge[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pre[v] = u;
                q.push({dis[v], v});
            }
        }
    }
}
int n, m, s1, s2;
int cnt = 0,ans = -1;
void dfs(int x) {
    if (x == s2) {
        ans = max(ans,cnt);
        cout << x << " " << cnt << endl;
        return;
    }
    for (auto [v, w] : edge[x]) {
        if (dis[v] == dis[x] + w) {
            cnt+=a[v];
            dfs(v);
            cnt-=a[v];
        }
    }
}
int main() {
    cin >> n >> m >> s1 >> s2;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edge[x].push_back({y, z});
        edge[y].push_back({x, z});
    }
    dij(s1);
    cout<<dis[s2] << endl;
    cnt=a[s1];
    dfs(s1);
    cout << ans << endl;
    return 0;
}