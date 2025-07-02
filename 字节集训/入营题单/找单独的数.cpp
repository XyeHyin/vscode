#include <bits/stdc++.h>
using namespace std;
int solution(std::vector<int> cards) {
    vector<int> a(1001, 0);
    for (int i = 0; i < cards.size(); i++) {
        a[cards[i]]++;
    }
    for (int i = 0; i < 1001; i++) {
        if (a[i] == 1) {
            return i;
        }
    }

    return 0;
}

int main() {
    // Add your test cases here

    std::cout << (solution({1, 1, 2, 2, 3, 3, 4, 5, 5}) == 4) << std::endl;
    std::cout << (solution({0, 1, 0, 1, 2}) == 2) << std::endl;

    return 0;
}
