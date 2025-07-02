#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    char a[1005][1005];
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    int cnt=0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
                if(a[i][j]=='*'&&a[i+1][j]=='*'&&a[i][j+1]=='*'&&a[i+1][j+1]=='*'){
                    cnt++;
                }
        }
    }
    cout << cnt << endl;
    return 0;
}