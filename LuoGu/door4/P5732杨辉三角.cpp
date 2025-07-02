#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int mapp[50][50] = {0};
    for (int i = 1; i <= n;i++){
        mapp[i][1] = mapp[i][i]=1;
    }
    for(int i=3;i<=n;i++){
        for(int j=2;j<=i;j++){
            if(mapp[i][j]==0)
            mapp[i][j]=mapp[i-1][j-1]+mapp[i-1][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << mapp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}