#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
vector<int> G[MAXN];
bool visited[MAXN];

void dfs(int v)
{
    visited[v] = true;
    for (int i = 0; i < G[v].size(); i++)
    {
        if (!visited[G[v][i]])
        {
            dfs(G[v][i]);
        }
    }
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 0; i < K; i++)
    {
        fill(visited, visited + N + 1, false);
        int lost;
        cin >> lost;
        visited[lost] = true;
        int cnt = 0;
        for (int j = 1; j <= N; j++)
        {
            if (!visited[j])
            {
                dfs(j);
                cnt++;
            }
        }
        cout << cnt - 1 << endl;
    }
    return 0;
}