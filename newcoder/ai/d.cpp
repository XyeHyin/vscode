#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll l, r, x, y, a, b;
    cin >> l >> r >> x >> y >> a >> b;
    if (x < y) {
        // 向右追逐
        // 1) 可能在跑到边界前就被追上（当 a>b 且跑的够久）
        if (a > b) {
            ll d = y - x;
            ll t_catch = (d + (a - b) - 1) / (a - b);
            // 如果在第 t_catch 轮前跑不到右边界
            if ((t_catch - 1) * b <= r - y) {
                cout << t_catch << "\n";
                return;
            }
        }
        // 2) 跑到右边界后再被追上
        ll t1 = ((r - y) + b - 1) / b; // 到达右边界所需轮数
        ll y1 = min(r, y + t1 * b);
        ll x1 = min(r, x + t1 * a);
        ll d1 = y1 - x1;          // 边界时的距离
        ll t2 = (d1 + a - 1) / a; // 边界后追上所需轮数
        cout << (t1 + t2) << "\n";
    } else {
        // x > y，向左追逐（对称处理）
        if (a > b) {
            ll d = x - y;
            ll t_catch = (d + (a - b) - 1) / (a - b);
            if ((t_catch - 1) * b <= y - l) {
                cout << t_catch << "\n";
                return;
            }
        }
        ll t1 = ((y - l) + b - 1) / b; // 到达左边界所需轮数
        ll y1 = max(l, y - t1 * b);
        ll x1 = max(l, x - t1 * a);
        ll d1 = x1 - y1;
        ll t2 = (d1 + a - 1) / a;
        cout << (t1 + t2) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}