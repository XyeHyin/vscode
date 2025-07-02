#include <bits/stdc++.h>
using namespace std;

int solution(int x_position, int y_position) {
    int n = abs(y_position - x_position);
    int p = 1;
    int currentSum = 0;
    int flatSteps = 0; 

    while (true) {
        // 计算上升阶段的和
        currentSum = std::accumulate(std::begin(std::vector<int>(p)),
                                     std::end(std::vector<int>(p)), 0);
        // 加上顶点停留的和
        currentSum += flatSteps * p;
        // 计算下降阶段的和
        currentSum += std::accumulate(std::begin(std::vector<int>(p - 1)),
                                      std::end(std::vector<int>(p - 1)), 0);

        // 如果当前序列的总和大于或等于 n，则退出循环
        if (currentSum >= n) {
            break;
        }

        // 如果增加顶点高度仍然不够，尝试增加顶点停留的步数
        if (currentSum + p < n) {
            ++p;
            flatSteps = 0;
        } else {
            // 增加顶点停留的步数，直到序列的总和等于 n
            while (currentSum < n) {
                ++flatSteps;
                currentSum += p;
            }
        }
    }

    // 计算序列长度
    int length = 2 * p - 1 + flatSteps;

    return length;
}

int main() {
    cout << solution(12, 6) << endl;  // 输出: 4
    cout << solution(34, 45) << endl; // 输出: 6
    cout << solution(50, 30) << endl; // 输出: 8
    return 0;
}