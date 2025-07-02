#include <bits/stdc++.h>
using namespace std;
string solution(int n, int k, string s) {
    for (int i = 0; i < n && k > 0; i++) {
        int pos = i;
        for (int j = i + 1; j < n && j - i <= k; j++) {
            if (s[j] < s[pos]) {
                pos = j;
            }
        }
        for (int j = pos; j > i; j--) {
            swap(s[j], s[j - 1]);
            k--;
        }
    }
    return s;
}
int main() {
    cout << (solution(5, 2, "01010") == "00101") << endl;
    cout << (solution(7, 3, "1101001") == "0110101") << endl;
    cout << (solution(4, 1, "1001") == "0101") << endl;
    return 0;
}