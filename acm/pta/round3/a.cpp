#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cnt = 0,ans = 0;
    while(true){
        int x;
        cin >> x;
        if(x<0) break;
        if(!(x%3)&&!(x%5)&&!(x%7)){
            cnt++;
            ans += x;
        }
    }
    cout << cnt << " " << ans << endl;
    return 0;
}