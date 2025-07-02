#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct XyeHyin{
    int att, den, mon;
    int tot;
};
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    XyeHyin now;
    cin >> now.att >> now.den >> now.mon;
    now.tot = now.att + now.den;
    int money;
    cin >> money;
    money += now.mon;
    vector<XyeHyin> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].att >> a[i].den >> a[i].mon;
        a[i].tot = a[i].att + a[i].den;
    }
    sort(a.begin(), a.end(), [&](XyeHyin a, XyeHyin b){
        return a.tot > b.tot;
    });
    if(now.tot >= a[0].tot){
        cout << now.tot << endl;
        return 0;
    }else{
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(now.tot >= a[i].tot){
                cout << now.tot << endl;
                return 0;
            }
           if(a[i].mon <= money){
                cout<<a[i].tot<<endl;
                return 0;
           }
        }
    }
    return 0;
}