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
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        ans ^= i;
    }
    cout << ans << endl;
    return 0;
}