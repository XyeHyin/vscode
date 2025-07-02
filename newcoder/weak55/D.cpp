#include <bits/stdc++.h>
using namespace std;
struct Node {
    int x, y, dist;
};
int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dist(n, vector<int>(n, 0x3f3f3f3f));
    queue<Node> q;
    q.push({0, 0, 0});
    dist[0][0] = 0;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while (!q.empty()) {
        Node node = q.front();
        q.pop();
        int x = node.x, y = node.y, d = node.dist;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && a[nx][ny] == 0 &&
                dist[nx][ny] > d + 1) {
                dist[nx][ny] = d + 1;
                q.push({nx, ny, d + 1});
            }
        }
        bool heng = true, shu = true;
        for (int i = 0; i < n; i++) {
            if (a[x][i] == 1)
                heng = false;
            if (a[i][y] == 1)
                shu = false;
        }
        if (heng) {
            for (int i = 0; i < n; i++) {
                if (dist[x][i] > d + 1) {
                    dist[x][i] = d + 1;
                    q.push({x, i, d + 1});
                }
            }
        }
        if (shu) {
            for (int i = 0; i < n; i++) {
                if (dist[i][y] > d + 1) {
                    dist[i][y] = d + 1;
                    q.push({i, y, d + 1});
                }
            }
        }
    }
    int ans = dist[n - 1][n - 1];
    if (ans == 0x3f3f3f3f) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}