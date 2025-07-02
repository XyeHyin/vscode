#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n, m;
    int cnt;

    bool check(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

    void dfs(int x, int y, vector<vector<char>> &grid) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check(nx, ny) && grid[nx][ny] == '1') {
                grid[nx][ny] = '0';
                dfs(nx, ny, grid);
            }
        }
    }

  public:
    int numIslands(vector<vector<char>> &grid) {
        n = grid.size();
        m = grid[0].size();
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;
    }
};
int main(){
    Solution s;
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                  {'1', '1', '0', '1', '0'},
                                  {'1', '1', '0', '0', '0'},
                                  {'0', '0', '0', '0', '0'}};
    std::cout<<s.numIslands(grid)<<std::endl;
    return 0;
}