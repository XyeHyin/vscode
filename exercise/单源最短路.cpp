#include <bits/stdc++.h>
using namespace std;
int dist[1001];
int s[1001];
int inf = 0x3f3f3f3f;
int g[1001][1001];
int n, m;
int dij(int v){
    int i, j, mindis,u;
    for (i = 1; i <= n; i++) {
        dist[i] = g[v][i];
        s[i] = 0;
    }
    s[v] = 1;
    for (i = 1; i <= n; i++) {
        mindis = inf;
        for ( j = 1; j <=n ; j++) {
            if(s[j]==0&&dist[j]<mindis){
                mindis = dist[j];
                u = j;
            }
        }
        s[u] = 1;
        for (j = 1; j <= n; j++) {
            if(s[j]==0){
                if(g[u][j]<inf&&dist[u]+g[u][j]<dist[j]){
                    dist[j] = dist[u] + g[u][j];
                }
            }
        }
    }
    return 0;
};
int main(){
    int a, b, c ,i, j;
    memset(s, 0, sizeof(s));
   for (int i = 1; i <= n; i++) {
     for (int j = 1; j <= n ; j++) {
        g[i][j] = inf;
     }
     g[i][i] = 0;
   }
}