#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n;
vector<vector<int>> adj;
int depth_node = 0;

int dfs(int u, int parent) {
    int max_depth = 0;
    for (auto &v : adj[u]) {
        if (v != parent) {
            max_depth = max(max_depth, dfs(v, u));
        }
    }
    return max_depth + 1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // 初始深度
    int initial_depth = dfs(1, -1);
    // 由于操作复杂，暂时输出初始深度
    cout << initial_depth << endl;
    return 0;
}