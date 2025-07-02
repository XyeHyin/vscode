#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, m, len;
int c[maxn] = {0};
#define lowbit(x) (x & -x)
#define int long long
int sum(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += c[i];
    return res;
}
void add(int x, int y) {
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += y;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n >> len;
    while (m--) {
        int op;
        cin >> op;
        if (op == 0) {
            int x, e;
            cin >> x >> e;
            while (e != 0 && x <= n) {
                add(x, e);
                x += len;
                e > 0 ? e-- : e++;
            }
        } else {
            int l, r;
            cin >> l >> r;
            cout << sum(r) - sum(l - 1) << endl;
        }
    }
    return 0;
}