#include <bits/stdc++.h>
using namespace std;
#define int long long
bool isprime(int n){
    for (int i = 2; i <= sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
signed main(){
    int l, r;
    cin >> l >> r;
    int ans = -1;
    for (int i = l;i<=r;i++){
        if(isprime(i)){
            continue;
        }
        for (int j = 2; j <=i;j++){
         if(i%j==0){
             ans = max(ans,i/j);
             break;
         }
        }
    }
    cout << ans << endl;
        return 0;
}