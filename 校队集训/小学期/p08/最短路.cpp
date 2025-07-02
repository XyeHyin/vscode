#include <bits/stdc++.h>
using namespace std;
const int N = 200, n = 19;
int dist[N];
int s[1001];
int g[N][N];
void add(char x, char y, int c) {
    int a = x - 'A' + 1;
    int b = y - 'A' + 1;
    g[a][b] = g[b][a] = c;
}
int dij(int v) {
    int i, j, mindis, u;
    for (i = 1; i <= n; i++) {
        dist[i] = g[v][i];
        s[i] = 0;
    }
    s[v] = 1;
    for (i = 1; i <= n; i++) {
        mindis = 0x3f3f3f3f;
        for (j = 1; j <= n; j++) {
            if (s[j] == 0 && dist[j] < mindis) {
                mindis = dist[j];
                u = j;
            }
        }
        s[u] = 1;
        for (j = 1; j <= n; j++) {
            if (s[j] == 0) {
                if (g[u][j] < 0x3f3f3f3f && dist[u] + g[u][j] < dist[j]) {
                    dist[j] = dist[u] + g[u][j];
                }
            }
        }
    }
    return 0;
}
int main(){
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) {
            g[i][j] = 0x3f3f3f3f;
        }
        g[i][i] = 0;
    }
    add('A', 'B', 2);
    add('A', 'C', 1);
    add('A', 'D', 1);
    add('A', 'D', 1);
    add('B', 'J', 2);
    add('B', 'G', 1);
    add('C', 'D', 3);
    add('C', 'F', 3);
    add('C', 'G', 3);
    add('D', 'E', 1);
    add('D', 'G', 2);
    add('D', 'H', 1);
    add('D', 'I', 2);
    add('E', 'H', 1);
    add('E', 'I', 3);
    add('F', 'G', 1);
    add('F', 'J', 1);
    add('G', 'F', 1);
    add('G', 'I', 3);
    add('G', 'K', 2);
    add('H', 'I', 1);
    add('H', 'L', 2);
    add('I', 'M', 3);
    add('J', 'S', 2);
    add('K', 'N', 1);
    add('K', 'L', 3);
    add('K', 'P', 2);
    add('L', 'M', 1);
    add('L', 'R', 1);
    add('M', 'N', 2);
    add('M', 'Q', 1);
    add('M', 'S', 1);
    add('N', 'P', 1);
    add('O', 'P', 1);
    add('O', 'Q', 1);
    add('O', 'R', 3);
    add('R', 'S', 1);
    dij(1);
    cout<<dist[19]<<endl;
    return 0;
}