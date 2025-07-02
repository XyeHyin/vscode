#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;
    cin >>n;
    ll dp[100][100]={0};
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    for(ll i=1;i<=500;i++){
            dp[i][i]=1;
            dp[i][1]=1;       
    }
    
    for(ll i=3;i<=100;i++){
        for(ll j=2;j<=i;j++){
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }
    return 0;
}