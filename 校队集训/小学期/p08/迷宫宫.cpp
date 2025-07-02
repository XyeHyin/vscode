#include <bits/stdc++.h>
using namespace std;
char mp[30][50] = {0};
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ans = INT_MAX;
int n = 30, m = 50;
string res = "";

void dfs(int x, int y, int step, string &path) {
    if (x == n - 1 && y == m - 1) {
        if (step < ans) {
            ans = step;
            res = path;
        }
        return;
    }
    char directions[] = {'R', 'D', 'L', 'U'};
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && mp[nx][ny] == '0') {
            path += directions[i];
            mp[nx][ny] = '1';
            dfs(nx, ny, step + 1, path);
            path.pop_back();
            mp[nx][ny] = '0';
        }
    }
}

int main() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
        }
    }
    string path = "";
    dfs(0, 0, 0, path);
    if (ans == INT_MAX) {
        cout << "No path found" << endl;
    } else {
        cout << ans << endl;
        cout << res << endl;
    }
    return 0;
}