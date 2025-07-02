#include <bits/stdc++.h>
using namespace std;
std::vector<int> solution(int n, int max, const std::vector<int> &array) {
    vector<int> a(14, 0);
    for (int i = 0; i < n; i++) {
        a[array[i]]++;
    }
    set<int> th, tw;
    for (int i = 1; i < 14; i++) {
        if (a[i] >= 3) {
            th.insert(i);
        }
        if (a[i] >= 2) {
            tw.insert(i);
        }
    }
    int ans = 0, ansi = 0, ansj = 0;
    for (auto i : th) {
        for (auto j : tw) {
            if (i != j) {
                if (i * 3 + j * 2 <= max) {
                    if (i > ansi && ansi != 1) {
                        ans = i * 3 + j * 2;
                        ansi = i;
                        ansj = j;
                    } else if (i == 1 && ansi != 1) {
                        ans = i * 3 + j * 2;
                        ansi = i;
                        ansj = j;
                    }else if (i == ansi) {
                        if (j > ansj && ansj != 1) {
                            ans = i * 3 + j * 2;
                            ansi = i;
                            ansj = j;
                        } else if (j == 1 && ansj != 1) {
                            ans = i * 3 + j * 2;
                            ansi = i;
                            ansj = j;
                        }
                    } 
                }
            }
        }
    }
    if (ans != 0) {
        return {ansi, ansj};
    }

    return {0, 0};
}

int main() {
    // Add your test cases here

    std::vector<int> result1 = solution(9, 34, {6, 6, 6, 8, 8, 8, 5, 5, 1});
    std::cout << (result1 == std::vector<int>{8, 5}) << std::endl;

    std::vector<int> result2 = solution(9, 37, {9, 9, 9, 9, 6, 6, 6, 6, 13});
    std::cout << (result2 == std::vector<int>{6, 9}) << std::endl;

    std::vector<int> result3 = solution(9, 40, {1, 11, 13, 12, 7, 8, 11, 5, 6});
    std::cout << (result3 == std::vector<int>{0, 0}) << std::endl;

    return 0;
}
