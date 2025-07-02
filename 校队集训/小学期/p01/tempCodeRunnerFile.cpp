#include <bits/stdc++.h>
using namespace std;

int a[20][20] = {0};

// 检查在第x行，第y列放置皇后是否合法
bool check(int n, int x, int y) {
    for (int i = 0; i < x; i++) {
        // 处理边界
        if (a[i][y] == 1 ||
            (y - x + i >= 0 && a[i][y - x + i] == 1) ||
            (i + y - x >= 0 && a[i][i + y - x] == 1)) {
            return false;
        }
    }
    return true;
}

int cnt = 0;

// 尝试在第x行放置皇后
void ff(int n, int x) {
    if (x == n) { // 所有的皇后都已经放置好了
        cnt++;
        if (cnt <= 3) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (a[i][j] == 1) {
                        cout << j + 1 << " ";
                    }
                }
            }
            cout << endl;
        }
        return;
    }
    for (int y = 0; y < n; y++) {
        if (check(n, x, y)) {
            a[x][y] = 1;     // 放置皇后
            ff(n, x + 1); // 移动到下一行
            a[x][y] = 0;     // 回溯，撤销皇后
        }
    }
}

void f(int n) {
    ff(n, 0);
}

int main() {
    int n;
    cin >> n;
    f(n);
    cout << cnt; // 打印解决方案的数量
    return 0;
}