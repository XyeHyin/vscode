#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool flag(int num) {
    std::string s = std::to_string(num);
    char c = s[0];
    for (char ch : s) {
        if (ch != c) {
            return false;
        }
    }
    return true;
}
int solution(int x, int y) {
    int cnt = 0;
    for (int i = x; i <= y; ++i) {
        if (flag(i)) {
            ++cnt;
        }
    }
    return cnt;
}

int main() {
    // 测试用例
    std::cout << (solution(1, 10) == 9) << std::endl;
    std::cout << (solution(2, 22) == 10) << std::endl;

    return 0;
}