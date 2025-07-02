#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin >> t;
    while(t--){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if (a[i] < 0) {
            cnt++;
            while (i <= n && a[i] <= 0) {
                a[i] = abs(a[i]);
                i++;
            }
        }
    }
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum += a[i];
    }
    cout<<sum<<" "<<cnt<<endl;
    }
    return 0;
}