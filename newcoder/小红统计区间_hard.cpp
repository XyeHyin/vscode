#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1000010;
int p = 1e18;
int a[maxn], w[maxn * 4], lzy_add[maxn * 4], lzy_mul[maxn * 4];
void pushup(const int u) { w[u] = (w[u * 2] + w[u * 2 + 1]) % p; }
void build(const int u, int L, int R) {
    if (L == R) {
        w[u] = a[L];
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
    if (type == 1) {
        (lzy_add[u] *= x) %= p;
        (lzy_mul[u] *= x) %= p;
        (w[u] *= x) %= p;
    } else {
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
int query(int u, int L, int R, int l, int r) {
    if (l <= L && R <= r)
        return w[u];
    else if (!OutofRange(L, R, l, r)) {
        int M = (L + R) / 2;
        pushdown(u, L, R);
        return (query(u * 2, L, M, l, r) + query(u * 2 + 1, M + 1, R, l, r)) %
               p;
    } else
        return 0;
}
void update(int u, int L, int R, int l, int r, int x, int type) {
    if (type == 1) {
        if (l <= L && R <= r) {
            maketag(u, L, R, x, 1);
        } else if (!OutofRange(L, R, l, r)) {
            int M = (L + R) / 2;
            pushdown(u, L, R);
            update(u * 2, L, M, l, r, x, 1);
            update(u * 2 + 1, M + 1, R, l, r, x, 1);
            pushup(u);
        }
    } else if (type == 2) {
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
signed main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    int ans = 0;
    for (int i = 1; i <= n;i++){
        for (int j = i; j <= n;j++){
            if(query(1, 1, n, i, j) >= k){
                ans++;
            }
        }
    }
    cout << ans << endl;
        return 0;
}