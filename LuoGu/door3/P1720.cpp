#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    double n;
    cin >> n;
    vector<double> a(n+1);
    a[0] = 1;
    a[1] = 1;
    for(int i=2;i<=n;i++){
        a[i]=a[i-1]+a[i-2];
    }
    printf("%.2f", a[n-1]);
    return 0;
}