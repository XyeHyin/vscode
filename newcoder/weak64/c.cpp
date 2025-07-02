#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> mp;
    vector<int> ans(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += mp[a[i]];
        mp[a[i]]++;
        ans[i] = cnt;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}