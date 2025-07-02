#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int l, m;
    cin >> l >> m;
    vector<int> a(l + 10, 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        for (int j = u; j <= v; j++) {
            a[j] = 0;
        }
    }
    int cnt = 0;
    for (int i = 0; i <= l; i++)cnt += a[i];
    cout << cnt << endl;
    if (a[217]) cout << "Little_X" << endl;
    else cout << "Nothing" << endl;
    if (a[316]) cout << "Little_H" << endl;
    else cout << "Nothing" << endl;
    return 0;
}