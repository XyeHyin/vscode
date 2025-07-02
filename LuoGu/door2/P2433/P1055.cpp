#include <bits/stdc++.h>
using namespace std;
int main(){
    int n[11];
    char end;
    scanf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%c", &n[1], &n[2], &n[3], &n[4], &n[5], &n[6], &n[7], &n[8], &n[9], &end);
    int ans = 0;
    for (int i = 1; i <= 9;i++){
       ans+=n[i]*i;
    }
    end = end == 'X' ? 10 : end - '0';
    ans %= 11;

    if(ans==end||ans==10&&end=='X'){cout<<"Right"<<endl;}
    else{
        ans==10? printf("%d-%d%d%d-%d%d%d%d%d-%c\n", n[1], n[2], n[3], n[4], n[5], n[6], n[7], n[8], n[9], 'X'):
        printf("%d-%d%d%d-%d%d%d%d%d-%d\n", n[1], n[2], n[3], n[4], n[5], n[6], n[7], n[8], n[9], ans);
    }
        return 0;
}