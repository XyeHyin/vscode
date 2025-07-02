#include <bits/stdc++.h>
using namespace std;
int g[101][101];
int lowcost[101];
int closest[101];
int n;
int sum;
int prim(int v){
    int minv, i, j, k;
    sum = 0;
    for (i = 1; i <= n; i++){
        lowcost[i] = g[v][i];
        closest[i] = v;
    }
    for (i = 1; i < n;i++){
        minv = 0x3f3f3f3f;
        k = -1;
        for (j = 1; j <= n; j++){
            if (lowcost[j] != 0 && lowcost[j] < minv){
                minv = lowcost[j];
                k = j;
            }
        }
        if(k==-1)return -1;
        lowcost[k] = 0;
        sum += minv;
        for (j = 1; j <= n; j++){
            if (lowcost[j] != 0 && g[k][j] < lowcost[j]){
                lowcost[j] = g[k][j];
                closest[j] = k;
            }
        }
    }
    return sum;
}
int main()
{
    int i, j,m;
    cin >> n>>m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            g[i][j] = 0x3f3f3f3f;
        }
        g[i][i] = 0;
    }
    for (int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = c;
        g[b][a] = c;
    }
        cout << prim(1) << endl;
}
