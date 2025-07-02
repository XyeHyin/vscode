#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    if(k==n){
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            cout<<1<<" ";
        }
        return 0;
    }
    if (k > n) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int tmp;
    for (int i = 1; i <= k+1; i++) {
        if(i&1){
            cout << 1 << " ";
            tmp = 1;
        }else{
            cout << 2 << " ";
            tmp = 2;
        }
    }
    if(k+2==n){
        return 0;
    }
    for (int i = k+2; i <= n; i++) {
        cout << tmp << " ";
    }

    return 0;
}