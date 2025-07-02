#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int L = 0, R = n - 1;
    int max = 0;
    for(int i = 0; i < m; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum+=a[j][i];
        }
        if(sum>max)max = sum; 
    }
    cout << max << endl;
}