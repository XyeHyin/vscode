#include <bits/stdc++.h>
using namespace std;
#define int long long
bool isprime(int n) {
    if(n == 0||n==1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
signed main(){
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (isprime(i)) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}