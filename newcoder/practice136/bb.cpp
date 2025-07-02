#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 || i % 37 == 0) a.push_back(i);
        else b.push_back(i);
    }
    int cnt = a.size();
    vector<int> DS;
    int i = 1;
    while (i <= n) {
        if (i + 1 <= n) {
            DS.push_back(i + 1);
            i += 3;
        } else {
            DS.push_back(n);
            break;
        }
    }
    int need = DS.size();
    if (cnt < need) {
        cout << "Baka!";
        return;
    }

    // 构造答案：
    // 对于 DS 中的位置使用 a 蛙（取前 need 个a青蛙即可），
    // 其余位置使用 b 蛙（顺序任意）。
    vector<int> ans(n + 1, 0); // 1-indexed
    int idxa = 0, idxNon = 0;

    // 标记 DS 位置
    vector<bool> isDS(n + 1, false);
    for (auto pos : DS)
        isDS[pos] = true;

    for (int pos = 1; pos <= n; pos++) {
        if (isDS[pos]) {
            ans[pos] = a[idxa++];
        } else {
            ans[pos] = b[idxNon++];
        }
    }

    // 输出答案
    for (int pos = 1; pos <= n; pos++) {
        cout << ans[pos] << (pos < n ? " " : "");
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}