#include <bits/stdc++.h>
using namespace std;
int g[101][101];
int lowcost[101];
int closest[101];
const int INF = 999999;
int n;
int sum;
int prim(int v){
    int minv, i, j, k;
    sum = 0;
    for (i = 1; i <= n; i++) {
        lowcost[i] = g[v][i];
        closest[i] = v;
    }
    for (i = 1; i < n;i++){
        minv = 0x3f3f3f3f;
        for (j = 1; j <= n;j++){
            if(lowcost[j]!=0&&lowcost[j]<minv){
                minv = lowcost[j];
                k = j;
            }
        }
        lowcost[k] = 0;
        sum += minv;
        for (j = 1; j < n; i++) {
            if(lowcost[j]!=0&&g[k][j]<lowcost[j]){
                lowcost[j] = g[k][j];
                closest[j] = k;
            }
        }
    }
    return 0;
}
int main(){
    int i, j;
    cin >> n;
    for (int i = 1; i <= n;i++){
        for (int i = 1; i <= j; i++) {
            cin >> g[i][j];
        }
    }
    prim(1);
    cout << sum << endl;
}
