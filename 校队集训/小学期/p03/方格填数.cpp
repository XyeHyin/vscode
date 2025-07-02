#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
    int a[3][4];
    bool flag[10];
    int b[10][2]={
        {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}, {0, 0}, {1, 1}, {2, 2}, {3, 3}
    };
void dfs(int n){
    if(n==10){
        for (int i = 0; i < 3;i++){
            for (int j = 0; j < 4;j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}
int main(){
    
    return 0;
}
