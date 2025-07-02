#include <bits/stdc++.h>
using namespace std;
int main() {
    int k, i = 1;
    double ans = 0;
    cin >> k;
    while (true) {
        if (ans > k*1.0)break;
        ans += 1.0 / i;
        i++;
    }
    cout << --i << endl;
    return 0;
}