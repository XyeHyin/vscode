#include <bits/stdc++.h>
using namespace std;
long long fastPow(long long base, long long power, long long mod) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        power >>= 1;
    }
    return result;
}
int main(){
       int a, b, p;
       cin >> a >> b >> p;
       printf("%d^%d mod %d=%d\n", a, b, p, fastPow(a, b, p));   
    return 0;
}