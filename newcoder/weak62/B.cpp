#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, ini;
    cin >> n >> ini;
    if(ini==0){
        cout << 0;
        return 0;
    }
    int dis = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if(ini>0){
            ini -= a;
            dis += a;
        }else if(ini<0){
            ini += a;
            dis += a;
        }else{
            break;
        }
    }
    cout << dis;
    return 0;
}