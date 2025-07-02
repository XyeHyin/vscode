#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    vector<int> a(100005);
    int sum = 0;
    for (int i = 1; i <= 100000;i++){
        cin>>a[i];
        sum += a[i];
    }
    int ans = 0;
    for (int i = 1; i <= 100000;i++){
        sum-=a[i];
         ans+=a[i]*(sum);
    }
    cout << ans << endl;
        return 0;
}