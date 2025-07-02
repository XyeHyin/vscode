#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(const vector<string> &numbers, int index, int current_sum,
         int &count) {
    if (index == numbers.size()) {
        if (current_sum % 2 == 0) {
            count++;
        }
        return;
    }
    for (char c : numbers[index]) {
        int num = c - '0';
        dfs(numbers, index + 1, current_sum + num, count);
    }
}

int solve(const vector<string> &numbers) {
    int count = 0;
    dfs(numbers, 0, 0, count);
    return count;
}

int main() {
    vector<string> numbers1 = {"123", "456", "789"};
    cout << solve(numbers1) << endl; // 输出: 14

    vector<string> numbers2 = {"123456789"};
    cout << solve(numbers2) << endl; // 输出: 4

    vector<string> numbers3 = {"14329", "7568"};
    cout << solve(numbers3) << endl; // 输出: 10

    return 0;
}