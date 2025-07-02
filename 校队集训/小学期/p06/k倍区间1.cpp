#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0;i<n;i++){
        cin >> v[i];
    }
    vector<int> ans(n);
    int cnt = 0;
    for (int j = 0;j<n;j++){
        ans[j] = v[j];
        if (ans[j] % k == 0) {
            cnt++;
        }
        for (int i = j+1; i < n; i++) {
            ans[i] = ans[i - 1] + v[i];
            if (ans[i] % k == 0) {
                cnt++;
            }
        }
        ans.clear();
    }
    cout << cnt;
    return 0;
}