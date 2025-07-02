#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, m;
    cin >> n >> m;
    int a[n+1][m+1];
    int counta = 0,countb = 0;
    for (int i = 0; i <= n;i++){
        for (int j = 0; j <= m;j++){
            if(i==j){
                counta+=(n-i)*(m-j);
            }else{
                countb+=(n-i)*(m-j);
            }
        }
    }
    cout << counta << " " << countb;
    return 0;
}