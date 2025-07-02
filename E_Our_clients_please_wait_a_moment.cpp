#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, m;
int dist[maxn];
int s[maxn];
int inf = LLONG_MAX;
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
    int a, b, c;
    cin >> n >> a >> b >> c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int z;
            cin >> z;
            g[i][j] = min(z * a, z * b + c);
        }
        g[i][i] = 0;
    }
    dij(1);
    cout << dist[n] << endl;
    return 0;
}