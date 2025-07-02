#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> array) {
    map<int, int> m;
    for (int i = 0; i < array.size(); i++) {
        m[array[i]]++;
    }
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second > array.size() / 2) {
            return it->first;
        }
    }

    return 0;
}

int main() {
    // Add your test cases here

    cout << (solution({1, 3, 8, 2, 3, 1, 3, 3, 3}) == 3) << endl;

    return 0;
}
