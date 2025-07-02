#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    long long sum = 0; // 使用 long long 避免整数溢出
    int negativeCount = 0;
    int minAbsValue = INT_MAX;
    bool hasZero = false;

    for (int i = 1; i <= n; i++) {
        if (a[i] < 0) {
            negativeCount++;
            sum += -a[i]; // 将负数转为正数并加到总和中
        } else {
            sum += a[i]; // 直接加到总和中
            if (a[i] == 0)
                hasZero = true; // 检查是否有零
        }
        minAbsValue = min(minAbsValue, abs(a[i])); // 更新最小绝对值
    }

    int operations = 0;
    if (negativeCount % 2 != 0 && !hasZero) {
        // 如果负数数量为奇数且没有零，需要一次操作
        sum -= 2 * minAbsValue; // 减去两倍的最小绝对值，模拟将其变为正数
        operations = 1;
    }

    cout << sum << " " << operations << endl;

    return 0;
}