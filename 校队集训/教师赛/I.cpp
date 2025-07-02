#include <bits/stdc++.h>
using namespace std;

int zuhe(int n, int m) {
    if (n > m)
        return 0;
    if (n == 0 || n == m)
        return 1;
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result = result * (m - i + 1) / i;
    }
    return result;
}
int main() {
    int m, n;
    cin >> m >> n;
    cout << zuhe(m - 1, n + m - 1) << endl;
    return 0;
}