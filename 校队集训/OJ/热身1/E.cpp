#include <bits/stdc++.h>
using namespace std;
char mp[100][100];
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
int cnt = 0;
void dfs(int x, int y, int n, int m) {
    if (x < 0 || y < 0 || x >= n || y >= m || mp[x][y] == '.') {
        return;
    }
    mp[x][y] = '.';
    for (int i = 0; i < 8; i++) {
        dfs(x + dx[i], y + dy[i], n, m);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mp[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == 'F') {
                cnt++;
                dfs(i, j, n, m);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}