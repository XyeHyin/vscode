#include <bits/stdc++.h>
#define L using
#define S namespace
#define Y std
#define endl '\n'
// #define int long long
#define unsigned int
#define lowbit(x) (x & (-x))
const int N = 1e5 + 10;
// const int M = 0x3f3f3f3f;
const int mod = 1e9 + 7;
// const int mod = 998244353;
// L S Y;
// int xx[] = {-1, 0, 1, 0}, yy[] = {0, 1, 0, -1}; // (-1, 0) (0, 1) (1, 0) (0,
// -1)

int n, m, v, g, x, y, z, l, r, q;
int a[N], f1[N][30], f2[N][30], lg[N];

int query(int x, int y, int op) {
    int k = lg[y - x + 1];
    if (op == 1)
        return f1[x][k] & f1[y + 1 - (1 << k)][k];
    else
        return f2[x][k] | f2[y + 1 - (1 << k)][k];
}

void solve() {
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        f1[i][0] = f2[i][0] = a[i];
        if (i > 1)
            lg[i] = lg[i >> 1] + 1;
    }
    for (int j = 1; j <= lg[n]; j++) {
        for (int i = 1; i <= n + 1 - (1 << j); i++) {
            f1[i][j] = f1[i][j - 1] & f1[i + (1 << (j - 1))][j - 1];
            f2[i][j] = f2[i][j - 1] | f2[i + (1 << (j - 1))][j - 1];
        }
    }
    int id, k;
    while (q--) {
        std::cin >> id >> k;
        if (a[id] < k - a[id] || a[id] > k + a[id]) {
            std::cout << -1 << endl;
            continue;
        }
        l = 1, r = id;
        int mid;
        while (l < r) {
            mid = l + r >> 1;
            if (query(mid, id, 1) >= k - a[id])
                r = mid;
            else
                l = mid + 1;
        }
        std::cout << r << ' ';
        l = id, r = n;
        while (l < r) {
            mid = l + r + 1 >> 1;
            if (query(id, mid, 2) <= k + a[id]) {
                std::cout <<"l=mid:"<< mid << endl;
                l = mid;
            } else{
                std::cout << "r=mid:" << mid << endl;
                r = mid - 1;
            }
        }
        std::cout << l << endl;
    }
}

signed main() {
    int t;
    std::cin >> t;
    //	int t = 1;
    while (t--)
        solve();
    return 0;
}