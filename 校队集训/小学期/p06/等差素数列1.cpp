#include <bits/stdc++.h>
using namespace std;
bool isprime(int n){
    if(n==1) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    int n;
    n = 10;
    int sum = 1;
    for (int i = 1;i<=n;i++){
        if(isprime(i)) sum *= i;
    }
    cout << sum;
        return 0;
}