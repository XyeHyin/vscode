#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=1000;
    ;
    int a[50]={0,1};
    int b[50]={0,1};
    int c[50]={0,1};
    for (int i = 2;i<50;i++){
        a[i] = i;
    }
    for (int i = 2;i<50;i++){
        b[i] = a[i-1]+b[i-1];
    }
    for (int i = 2;i<50;i++){
        c[i] = b[i-1]+c[i-1];
    }
    for (int i = 2;i<50;i++){
        if(c[i]>n){
            cout << i-1;
            break;
        }
    }
        return 0;
}