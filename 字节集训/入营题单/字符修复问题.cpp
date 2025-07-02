#include <bits/stdc++.h>
using namespace std;

int solution(int n, int m, string str1, string str2) {
    int ans = 0;
    for (char i = 'a'; i <= 'z'; i++) {
        int l = 0, r = 0, cnt = 0;
        while (r < n) {
            if (str1[r] != i && str2[r] == '1') {
                cnt++;
            }
            while (cnt > m) {
                if (str1[l] != i && str2[l] == '1') {
                    cnt--;
                }
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
    }
    return ans;
}

int main() {
    cout << (solution(5, 2, "abcda", "01110") == 3) << endl;
    cout << (solution(7, 2, "abbaccb", "1001001") == 4) << endl;
    cout << (solution(3, 0, "aab", "101") == 2) << endl;

    return 0;
}