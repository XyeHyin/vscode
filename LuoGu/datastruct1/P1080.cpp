#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    vector<pair<int, int>> a(n+1);
    for (int i = 0; i < n+1;i++){
        int aa, bb;
        cin >> aa >> bb;
        a[i] = {aa, bb};
    }
    sort(a.begin()+1, a.end(), [](pair<int, int> c, pair<int, int> d) {
        return c.first * c.second < d.first * d.second;
    });
    int mul = a[0].first;
    int ans = 0;
    for (int i = 1; i < n+1;i++){
        int temp = mul / a[i].second;
        mul *= a[i].first;
        ans = max(temp,ans);
    }
    cout << ans << endl;
    return 0;
}