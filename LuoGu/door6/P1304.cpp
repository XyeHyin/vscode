#include <bits/stdc++.h>
using namespace std;
bool isprime(int n) {
    if(n == 0||n==1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    for(int i=4;i<=n;i+=2){
        for(int j=0;j<=i/2;j++){
            if(isprime(j)&&isprime(i-j)){
               cout<<i<<"="<<j<<"+"<<i-j<<endl;
                break;
            }
        }
    }
    return 0;
}