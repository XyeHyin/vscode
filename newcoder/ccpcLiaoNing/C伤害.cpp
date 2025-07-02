#include <bits/stdc++.h>
using namespace std;
#define int long long
struct ene {
    int blo;
    int dam;
};
signed main() {
    int n;
    cin >> n;
    vector<ene> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].blo >> a[i].dam;
    }
    sort(a.begin(), a.end(), [](ene a, ene b) {
        if (a.dam == b.dam) return a.blo > b.blo;
        return a.dam > b.dam;
    });
    int ans = 0;
    queue<int> q;
    vector<bool> vis(n, 0);
    for (int i = 0; i < n; i++) {
        if (a[i].blo <= 0 || vis[i])  continue;
        ans++;
        q.push(i);
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            if (vis[p]) continue;
            vis[p] = 1;
            for (int j = 0; j < n; j++) {
                if (a[j].blo > 0) {
                    a[j].blo -= a[p].dam;
                    if (a[j].blo <= 0 && !vis[j]) {
                        q.push(j);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}