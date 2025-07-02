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
    int cnt = 0;
    while(n--){
        int x;
        cin >> x;
        if(x%9==0&&x%8!=0){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}