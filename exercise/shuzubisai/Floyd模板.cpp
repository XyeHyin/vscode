#include <bits/stdc++.h>
using namespace std;
int a[101][101];
int n, m, x, y, k, maxs, i, j;
int INF = 0x7fffffff;

int main(){
    for (int i = 1; i <=n ; i++) {
        for (int j = 1; j <= n;j++){
              a[i][j]=INF;
              a[y][x] = k;
        }
    }
    for (k = 1; k <= n;k++){
        for (i = 1; i <= n;i++){
            for (j = 1; j <= n;j++){
                if((i!=k&&j!=i&&j!=k)&&(a[i][k]+a[k][j]<a[i][j])){
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }
    maxs = 0;
    for (i = 1; i <= n;i++){

    }
}