#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int m, n, k;
    cin >> m >> n >> k;
    int sum = 0;
    while(m--){
        int x;
        cin >> x;
        sum+=x;
    }
    if(sum/(n+1)>=k) cout<<n+1<<endl;
    else cout<<sum/k<<endl;
    return 0;
}