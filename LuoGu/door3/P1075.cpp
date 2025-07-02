#include <bits/stdc++.h>
using namespace std;
bool isprime(int n){
    if(n==1)return false;
    for (int i = 2; i <= sqrt(n);i++){
        if(n%i==0)return false;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i = sqrt(n);i>=1;i--){
        if(n%i==0&&isprime(i)) ans=i;
    }
    cout<<n/ans<<endl;
        return 0;
}