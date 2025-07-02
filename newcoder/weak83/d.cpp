#include <bits/stdc++.h>
using namespace std;

#define int long long

// 返回完成第k对（2k步）后，甲虫所在的位置
// 若k为奇数，则位置为((k+1)/2, -(k+1)/2)
// 若k为偶数，则位置为(-k/2, k/2)
pair<int, int> posAfterPairs(int k) {
    if (k == 0)
        return {0, 0};
    if (k % 2 == 1) {
        // k奇数
        return {(k + 1) / 2, -(k + 1) / 2};
    } else {
        // k偶数
        return {-(k / 2), k / 2};
    }
}

// 根据方向和走的步数，返回新位置
pair<int, int> moveStep(pair<int, int> st, int dir, int len) {
    // dir顺序: 0=右,1=下,2=左,3=上
    // 但我们在这里直接用具体含义
    auto [x, y] = st;
    switch (dir) {
    case 0:
        return {x + len, y}; // right
    case 1:
        return {x, y - len}; // down
    case 2:
        return {x - len, y}; // left
    case 3:
        return {x, y + len}; // up
    }
    return {x, y};
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long t;
        cin >> t;
        // 当t=1时，位置就是(0,0)，没有移动
        if (t == 1) {
            cout << 0 << " " << 0 << "\n";
            continue;
        }
        // M = 移动的总步数 = t - 1
        long long M = t - 1;

        // 二分或直接套公式找到最大的 k 满足 k*(k+1) <= M
        // 也就是完成k对（2k步）之后仍不超过M
        // 这个k可能为0
        long long k =
            (long long)(floor((-1.0 + sqrt(1.0 + 4.0 * (long double)M)) / 2.0));
        // 检查可能的浮点偏差，做个调整
        while (k * (k + 1) > M)
            k--;
        while ((k + 1) * (k + 2) <= M)
            k++;

        long long donePairsSteps = k * (k + 1); // 完成 k 对后的总步数
        if (donePairsSteps == M) {
            // 恰好完成k对
            auto ans = posAfterPairs(k);
            cout << ans.first << " " << ans.second << "\n";
            continue;
        }

        // 还需要在第 (k+1) 对里走一些步
        long long offset = M - donePairsSteps; // 在第(k+1)对里还要走的步数
        // 第(k+1)对的长度是(k+1)
        // 若(k+1)为奇数 => 走向: 右, 下
        // 若(k+1)为偶数 => 走向: 左, 上
        auto startPos = posAfterPairs(k);
        int pairIndex = k + 1; // 当前要走的对编号
        // 确定第1段方向、第2段方向
        // 以 (奇对 -> {右,下}, 偶对 -> {左,上}) 的形式
        int dir1, dir2;
        if (pairIndex % 2 == 1) {
            // odd: right -> down
            dir1 = 0; // right
            dir2 = 1; // down
        } else {
            // even: left -> up
            dir1 = 2; // left
            dir2 = 3; // up
        }

        if (offset <= pairIndex) {
            // 全部在第一段方向里
            auto ans = moveStep(startPos, dir1, offset);
            cout << ans.first << " " << ans.second << "\n";
        } else {
            // 第一段走了 pairIndex 步，第二段走 offset - pairIndex 步
            auto midPos = moveStep(startPos, dir1, pairIndex);
            long long remain = offset - pairIndex;
            auto ans = moveStep(midPos, dir2, remain);
            cout << ans.first << " " << ans.second << "\n";
        }
    }
}

signed main() {
    solve();
    return 0;
}