#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 100010;
int a[maxn], w[maxn * 4], lzy[maxn * 4];
void pushup(const int u) { w[u] = w[u * 2] + w[u * 2 + 1]; }
void build(const int u, int L, int R) {
    if (L == R) {
        w[u] = a[L];
        return;
    }
    int M = (L + R) / 2;
    build(u * 2, L, M);
    build(u * 2 + 1, M + 1, R);
    pushup(u);
}
bool InRange(int L, int R, int l, int r) { return (l <= L) && (R <= r); }
bool OutofRange(int L, int R, int l, int r) { return (L > r) || (R < l); }
void maketag(int u, int len, int x) {
    lzy[u] += x;
    w[u] += len * x;
}
void pushdown(int u, int L, int R) {
    int M = (L + R) / 2;
    maketag(u * 2, M - L + 1, lzy[u]);
    maketag(u * 2 + 1, R - M, lzy[u]);
    lzy[u] = 0;
}
int query(int u, int L, int R, int l, int r) {
    if (l <= L && R <= r)
        return w[u];
    else if (!OutofRange(L, R, l, r)) {
        int M = (L + R) / 2;
        pushdown(u, L, R);
        return query(u * 2, L, M, l, r) + query(u * 2 + 1, M + 1, R, l, r);
    } else
        return 0;
}
void update(int u, int L, int R, int l, int r, int x) {
    if (l <= L && R <= r) {
        maketag(u, R - L + 1, x);
    } else if (!OutofRange(L, R, l, r)) {
        int M = (L + R) / 2;
        pushdown(u, L, R);
        update(u * 2, L, M, l, r, x);
        update(u * 2 + 1, M + 1, R, l, r, x);
        pushup(u);
    }
}
signed main() {
    int n, m,len;
    cin >> n >> m>>len;
    for (int i = 1; i <= m; i++) a[i] = 0;
    build(1, 1, m);
    for (int t = 1; t <= n; t++) {
        int op;
        cin >> op;
        if (op == 0) {
            int x, e;
            cin >> x >> e;
            while(x<=m&&e!=0){
                update(1, 1, m, x, x, e);
                x+=len;
                e<0?e++:e--;
            }
        } else if (op == 1) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, m, l, r) << endl;
        }
    }
    return 0;
}