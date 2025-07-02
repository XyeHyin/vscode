#include <bits/stdc++.h>
using namespace std;
int main(){
    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(r + 1, vector<int>(c + 1));
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> a[i][j];
        }
    }
    
    return 0;
}