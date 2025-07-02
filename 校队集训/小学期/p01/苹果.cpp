#include <bits/stdc++.h>
using namespace std;
// 提前声名
int f(int m, int n);
int g(int m, int n) {
    if (m < n)
        return 0;
    if (m == n)
        return 1;
    if (n == 1)
        return 1;
    return f(m - n, n);
}
int f(int m, int n) {
    if (n == 1)
        return 1;
    if (m == 1)
        return 1;
    if (n > m)
        return f(m, m);
    int sum = 0, i;
    for (int i = 1; i <= n; i++)
        sum += g(m, i);
    return sum;
}
int main() {
    cout<<f(6, 3);
    return 0;
}