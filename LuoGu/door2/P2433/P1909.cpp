#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, ans = 0x3f3f3f3f;
    cin >> n;
    for (int i = 0; i < 3;i++){
        long long a, b;
        cin >> a >> b;
        long long tma = a, tmb = b;
        while(tma<n){
            tma +=a;
            tmb +=b;
        }
        ans=min(ans, tmb);
    }
    cout << ans << endl;
        return 0;
}