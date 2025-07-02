#include <bits/stdc++.h>
using namespace std;

int solution(std::string input) {
    int n = input.size();
    int nn = n / 4;
    map<char, int> cnt;
    for (char c : input) {
        cnt[c]++;
    }
    int ans = n;
    int l = 0;
    for (int r = 0; r < n; ++r) {
        cnt[input[r]]--;
        while (l < n && cnt['A'] <= nn && cnt['S'] <= nn &&
               cnt['D'] <= nn && cnt['F'] <= nn) {
            ans = min(ans, r - l + 1);
            cnt[input[l]]++;
            l++;
        }
    }

    return ans;
}

int main() {
    // 你可以在这里添加更多的测试用例
    std::cout << (solution("ADDF") == 1) << std::endl;
    std::cout << (solution("ASAFASAFADDD") == 3) << std::endl;
    std::cout << (solution("SSDDFFFFAAAS") == 1) << std::endl;
    std::cout << (solution("AAAASSSSDDDDFFFF") == 0) << std::endl;
    std::cout << (solution("AAAADDDDAAAASSSS") == 4) << std::endl;
    return 0;
}