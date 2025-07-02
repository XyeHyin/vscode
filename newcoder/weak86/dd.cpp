#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define PII pair<int, int>
#define rep(i, x, n) for (int i = x; i <= n; i++)
#define dep(i, x, n) for (int i = x; i >= n; i--)
#define endl '\n'

int gcd(int a, int b) {
    while (b ^= a ^= b ^= a %= b)
        ;
    return a;
}

void solve() {
    int x, y;
    cin >> x >> y;
    if (x == 0 || y == 0) {
        cout << 0 << endl;
        return;
    }
    unordered_map<int, int> freq;
    vector<int> nodes;
    auto addNum = [&](int num, int ops, queue<PII> &q) {
        // 已经存在则只更新出现次数
        if (freq.count(num)) {
            freq[num]++;
        } else {
            freq[num] = 1;
            nodes.push_back(num);
            q.push({num, ops});
        }
    };

    queue<PII> q;
    // 初始加入两个数字，注意可能x==y，仍记录相应频次
    addNum(x, 0, q);
    addNum(y, 0, q);

    while (!q.empty()) {
        auto [curr, ops] = q.front();
        q.pop();
        // 为了避免遍历过程中nodes增长的问题，取当前快照
        vector<int> snapshot = nodes;
        for (int num : snapshot) {
            // 如果想选择两个相同数字，则必须保证该数字出现至少两次。
            if (curr == num && freq[curr] < 2)
                continue;
            // 对 curr 与 num 进行四种操作
            vector<int> results = {
                curr & num,    // 位与
                curr | num,    // 位或
                curr ^ num,    // 位异或
                gcd(curr, num) // 最大公约数
            };

            for (int result : results) {
                if (result == 0) {
                    cout << ops + 1 << endl;
                    return;
                }
                if (freq.find(result) == freq.end()) {
                    addNum(result, ops + 1, q);
                } else {
                    // 如果已经存在，该操作可能产生自配对后续效果，但实际上只需要新数字产生新组合
                    // 此处不重复入队
                }
            }
        }
    }
    cout << -1 << endl; // 题目保证能得到0，不会执行到这里
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}