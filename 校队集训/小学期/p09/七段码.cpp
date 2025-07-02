#include <bits/stdc++.h>
using namespace std;
bool op[8][8] = {false};
bool vis[8] = {false};
int a[8], ans = 0;
int find(int x) {
    if (x != a[x])
        a[x] = find(a[x]);
    return a[x];
}
void jion(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y)
        a[x] = y;
    return;
}
bool check() {
    int flag = 0;
    for (int i = 1; i <= 7; i++)
        a[i] = i;
    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            if (op[i][j] && vis[i] && vis[j])
                jion(i, j);
        }
    }
    for (int i = 1; i <= 7; i++) {
        if (vis[i] && a[i] == i)
            flag++;
    }
    if (flag == 1)
        return true;
    else
        return false;
}
void dfs(int k) {
    if (k == 8) {
        if (check()) ans++;
        return;
    } else {
        vis[k] = true;
        dfs(k + 1);
        vis[k] = false;
        dfs(k + 1);
    }
}
int main() {
    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            if (i == j)
                op[i][j] = true;
        }
    }
    op[1][2] = op[1][6] = true;
    op[2][1] = op[2][3] = op[2][7] = true;
    op[3][4] = op[3][7] = op[3][2] = true;
    op[4][3] = op[4][5] = true;
    op[5][4] = op[5][6] = op[5][7] = true;
    op[6][5] = op[6][1] = op[6][7] = true;
    op[7][2] = op[7][3] = op[7][5] = op[7][6] = true;
    dfs(1);
    cout << ans;
    return 0;
}