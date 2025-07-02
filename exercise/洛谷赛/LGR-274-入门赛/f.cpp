#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1000010;
const int p = 1e9 + 7;
int w[maxn * 4], lzy_add[maxn * 4], lzy_mul[maxn * 4];
void pushup(const int u) { w[u] = (w[u * 2] + w[u * 2 + 1]) % p; }
void build(const int u, int L, int R) {
    if (L == R) {
        w[u] = 0;
        return;
    }
    int M = (L + R) / 2;
    build(u * 2, L, M);
    build(u * 2 + 1, M + 1, R);
    pushup(u);
    lzy_mul[u] = 1;
}
bool InRange(int L, int R, int l, int r) { return (l <= L) && (R <= r); }
bool OutofRange(int L, int R, int l, int r) { return (L > r) || (R < l); }
void maketag(int u, int l, int r, int x, int type) {
    if (type == 1) { // 乘法
        (lzy_add[u] *= x) %= p;
        (lzy_mul[u] *= x) %= p;
        (w[u] *= x) %= p;
    } else { // 加法
        (lzy_add[u] += x) %= p;
        (w[u] += x * (r - l + 1)) %= p;
    }
}
void pushdown(int u, int L, int R) {
    int M = (L + R) / 2;
    maketag(u * 2, L, M, lzy_mul[u], 1);
    maketag(u * 2, L, M, lzy_add[u], 2);
    maketag(u * 2 + 1, M + 1, R, lzy_mul[u], 1);
    maketag(u * 2 + 1, M + 1, R, lzy_add[u], 2);
    lzy_mul[u] = 1;
    lzy_add[u] = 0;
}
void update(int u, int L, int R, int l, int r, int x, int type) {
    if (type == 1) { // 乘法
        if (l <= L && R <= r) {
            maketag(u, L, R, x, 1);
        } else if (!OutofRange(L, R, l, r)) {
            int M = (L + R) / 2;
            pushdown(u, L, R);
            update(u * 2, L, M, l, r, x, 1);
            update(u * 2 + 1, M + 1, R, l, r, x, 1);
            pushup(u);
        }
    } else if (type == 2) { // 加法
        if (l <= L && R <= r) {
            maketag(u, L, R, x, 2);
        } else if (!OutofRange(L, R, l, r)) {
            int M = (L + R) / 2;
            pushdown(u, L, R);
            update(u * 2, L, M, l, r, x, 2);
            update(u * 2 + 1, M + 1, R, l, r, x, 2);
            pushup(u);
        }
    }
}
int query(int u, int L, int R, int l, int r, int k) {
    if (OutofRange(L, R, l, r))
        return 0;
    if (L == R) {
        if (w[u] >= k) {
            w[u] = 0;
            return 1;
        }
        return 0;
    }
    pushdown(u, L, R);
    int M = (L + R) / 2;
    int cnt = 0;
    cnt += query(u * 2, L, M, l, r, k);
    cnt += query(u * 2 + 1, M + 1, R, l, r, k);
    pushup(u);
    return cnt;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    build(1, 1, n);
    for (int t = 1; t <= m; t++) {
        string op;
        cin >> op;
        if (op == "water") {
            int l, r;
            cin >> l >> r;
            update(1, 1, n, l, r, 1, 2);
        } else if (op == "rise") {
            int l, r, k;
            cin >> l >> r >> k;
            int ans = query(1, 1, n, l, r, k);
            cout << ans << endl;
        }
    }
    return 0;
}