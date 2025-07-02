#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int n, m;
int dist[maxn];
int s[maxn];
int inf = 0x3f3f3f3f;
int g[maxn][maxn];
int dij(int v) {
    int i, j, mindis, u;
    for (i = 1; i <= n; i++) {
        dist[i] = g[v][i];
        s[i] = 0;
    }
    s[v] = 1;
    for (i = 1; i <= n; i++) {
        mindis = inf;
        u = -1;
        for (j = 1; j <= n; j++) {
            if (s[j] == 0 && dist[j] < mindis) {
                mindis = dist[j];
                u = j;
            }
        }
        if (u == -1) {
            break;
        }
        s[u] = 1;
        for (j = 1; j <= n; j++) {
            if (s[j] == 0) {
                if (g[u][j] < inf && dist[u] + g[u][j] < dist[j]) {
                    dist[j] = dist[u] + g[u][j];
                }
            }
        }
    }
    return 0;
}
int main() {
    int ss;
    cin >> n >> m >> ss;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = inf;
        }
        g[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = c;
    }
    dij(ss);
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
}