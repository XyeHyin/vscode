#include <bits/stdc++.h>
using namespace std;
int g[100][100];
int a[100][100];
int path[100][100]={0};

int main(){
    //Ak[i][j]: i->j的路径上所经过的顶点编号不大于k的最短路径长度.
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            cin >> g[i][j];
        }
    }
        for (int k = 1; k <= n; k++) {
            path[k][k] = -1;
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++){
                    if (min(g[i][j], g[i][k] + g[k][j])!=g[i][j]) path[i][j]++;
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <=n ; j++) {
                cout << g[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
}