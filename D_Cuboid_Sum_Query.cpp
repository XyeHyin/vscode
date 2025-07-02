#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int N;
int A[MAXN][MAXN][MAXN];         // 原始数组
int prefix_2d[MAXN][MAXN][MAXN]; // 每层的二维前缀和
int prefix_3d[MAXN][MAXN][MAXN]; // 最终的三维前缀和

// 计算二维前缀和
void compute_2d_prefix(int z) {
    for (int x = 1; x <= N; ++x) {
        for (int y = 1; y <= N; ++y) {
            prefix_2d[x][y][z] = A[x][y][z] + prefix_2d[x - 1][y][z] +
                                 prefix_2d[x][y - 1][z] -
                                 prefix_2d[x - 1][y - 1][z];
        }
    }
}

// 构建三维前缀和（基于二维前缀和）
void build_3d_prefix() {
    for (int x = 1; x <= N; ++x) {
        for (int y = 1; y <= N; ++y) {
            for (int z = 1; z <= N; ++z) {
                prefix_3d[x][y][z] =
                    prefix_3d[x][y][z - 1] + prefix_2d[x][y][z];
            }
        }
    }
}

// 查询函数：使用三维前缀和快速求和
int query(int lx, int rx, int ly, int ry, int lz, int rz) {
    auto p = [&](int x, int y, int z) { return prefix_3d[x][y][z]; };

    return p(rx, ry, rz) - p(lx - 1, ry, rz) - p(rx, ly - 1, rz) -
           p(rx, ry, lz - 1) + p(lx - 1, ly - 1, rz) + p(lx - 1, ry, lz - 1) +
           p(rx, ly - 1, lz - 1) - p(lx - 1, ly - 1, lz - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    // 输入原始数组 A[x][y][z]
    for (int x = 1; x <= N; ++x) {
        for (int y = 1; y <= N; ++y) {
            for (int z = 1; z <= N; ++z) {
                cin >> A[x][y][z];
            }
        }
    }

    // 第一步：对每层 z，计算二维前缀和
    for (int z = 1; z <= N; ++z) {
        compute_2d_prefix(z);
    }

    // 第二步：在 z 方向上累加二维前缀和，形成三维前缀和
    build_3d_prefix();

    int Q;
    cin >> Q;

    // 处理所有查询
    while (Q--) {
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        cout << query(lx, rx, ly, ry, lz, rz) << '\n';
    }

    return 0;
}