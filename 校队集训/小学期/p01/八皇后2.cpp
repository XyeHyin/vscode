#include <bits/stdc++.h>
using namespace std;
int a[20][20] = {0};
bool test(int n, int m, int i) {
    int j;
    for (j = 0; j < m; j++) {
        if (a[j][i] == 1 || m + i - j < n && a[j][m + i - j] == 1 ||
            j + i - m >= 0 && a[j][j + i - m] == 1) {
            return false;
        }
    }
    return true;
}
void hh1(int n, int m) {
    if (m == n) {
        int i, j;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    int i;
    for (i = 0; i < n; i++) {
        if (test(n, m, i)) {
            a[m][i] = 1;
            hh1(n, m + 1);
            a[m][i] = 0;
        }
    }
}
void hh(int n) { hh1(n, 0); }
int main() {
    hh(4);
    return 0;
}