#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y, step;
    string path;
};

char mp[30][50]; 
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n = 30, m = 50; // 迷宫的实际大小，需要根据实际情况修改
string res = "";
int minStep = INT_MAX;
vector<string> results;

void bfs() {
    queue<Node> q;
    q.push({0, 0, 0, ""});
    // mp[0][0] = '1'; // 不在这里标记起点为已访问
    char directions[] = {'R', 'D', 'L', 'U'};
    while (!q.empty()) {
        Node node = q.front();
        q.pop();
        if (mp[node.x][node.y] == '1')
            continue;             // 如果当前节点已访问，则跳过
        mp[node.x][node.y] = '1'; // 访问当前节点
        if (node.x == n - 1 && node.y == m - 1) {
            if (node.step < minStep ||
                (node.step == minStep && node.path < res)) {
                minStep = node.step;
                results.push_back(node.path);
            }
            continue; // 不返回，继续搜索
        }
        for (int i = 0; i < 4; i++) {
            int nx = node.x + dx[i];
            int ny = node.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && mp[nx][ny] == '0') {
                q.push({nx, ny, node.step + 1, node.path + directions[i]});
            }
        }
    }
    if (res.empty()) {
        cout << "No path found" << endl;
    } else {
        cout << minStep << endl;
        cout << res << endl;
    }
}

int main() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
        }
    }
    bfs();
    sort(results.begin(), results.end());
    cout<<results[0]<<endl;
    return 0;
}