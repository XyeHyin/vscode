#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, d;
    cin >> t >> d;
    double ans = 0;
    bool flag = 0;
    if(t<0||t>24){
        cout<<"输入错误"<<endl;
        return 0;
    }
    if(t<5||t>=22) flag = 1;
    if(d<=3) {
        cout<<8<<endl;
        return 0;
    }
    d-=3;
    ans = 2 * d*(flag?1.3:1.0) + 8;
    printf("共花费%.2f\n", ans);
    return 0;
}