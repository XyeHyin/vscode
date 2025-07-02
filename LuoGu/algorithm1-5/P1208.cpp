#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(),[] (pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if(n == 0) break;
        int t = min(n, a[i].second);
        ans += t * a[i].first;
        n -= t;
    }
    cout << ans;
    return 0;
}