#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int xueshengshu;
    int cost = 0;
    while(a.size()!=1){
        xueshengshu = a[0]+a[1];
        cost += xueshengshu * 100;
        a.push_back(xueshengshu);
        a.erase(a.begin(),a.begin()+2);
        sort(a.begin(), a.end());
    }
    cout << cost << endl;
    return 0;
}