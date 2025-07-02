#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    while (b ^= a ^= b ^= a %= b);
    return a;
}
int main() {
    int n;
    cin >> n;
    if(n==1){
        cout<<0<<endl;
    }else if(n==2){
        cout<<2<<endl;
    }else if(n==3||n%2==0){
        cout<<4<<endl;
    }else{
        cout<<6<<endl;
    }
    return 0;
}