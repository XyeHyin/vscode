#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if(n&1){
        if((n-1)%4==0){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }else{
        if(((n-2)%4)==0) cout << n+1 << endl;
        else cout << n << endl;
    }
    return 0;
}