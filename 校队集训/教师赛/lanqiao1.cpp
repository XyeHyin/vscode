#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, x;
    cin >> a >> b >> x;
    int mod = pow(10, x);
    int ans = 1;
    while(b--) {
        ans =a*ans%mod;
    }
    cout << ans;
    return 0;
}