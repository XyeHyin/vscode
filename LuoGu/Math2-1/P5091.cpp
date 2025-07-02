#include <bits/stdc++.h>
using namespace std;
#define int long long
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
signed main(){
    int a, m, b;
    cin >> a >> m >> b;
    cout<<fastPow(a, b, m)<<endl;   
    return 0;
}