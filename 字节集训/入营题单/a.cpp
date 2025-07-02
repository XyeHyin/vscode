#include <iostream>
#include <string>
#include <vector>

int solution(int num) {
    std::string s = std::to_string(num);
    int n = s.size();
    std::vector<int> dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; --i) {
        dp[i] = dp[i + 1];
        if (i < n - 1) {
            int two_digit = std::stoi(s.substr(i, 2));
            if (two_digit >= 10 && two_digit <= 25) {
                dp[i] += dp[i + 2];
            }
        }
    }

    return dp[0];
}

int main() {
    std::cout << (solution(12258) == 5) << std::endl;
    std::cout << (solution(1400112) == 6) << std::endl;
    std::cout << (solution(2110101) == 10) << std::endl;
    std::cout << (solution(25) == 2) << std::endl;
    std::cout << (solution(1023) == 4) << std::endl;

    return 0;
}