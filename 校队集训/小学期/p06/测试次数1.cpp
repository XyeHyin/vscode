#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[100][100]={0};
    for(int i=0;i<100;i++){
        a[0][i]=i;
        a[i][0]=0;
    }
    for(int i=1;i<100;i++){
        for(int j=1;j<100;j++){
            a[i][j]=a[i-1][j-1]+a[i][j-1]+1;
        }
    }
    for (int i = 0; i < 100;i++){
        if(a[2][i]>1000){
            cout << i;
            break;
        }
    }

        return 0;
}