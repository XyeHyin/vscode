#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> a) {
    int ans = 0;
    for (int i = 1; i < (1 << n); i++) {
        int tmp = -1;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                if (tmp == -1) {
                    tmp = a[j];
                } else {
                    tmp &= a[j];
                }
            }
        }
        if(tmp == 0) continue;
        int m = 0;
        while (tmp > 0 && (tmp & 1) == 0) {
            tmp >>= 1;
            m++;
        }

        ans = max(ans, m);
    }

    return ans;
}

int main() {
    cout << (solution(5, {1, 2, 3, 20, 28})) << endl;
    cout << (solution(4, {16, 8, 4, 2})) << endl;
    cout << (solution(6, {7, 14, 28, 56, 112, 224})) << endl;
    return 0;
}