#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    while (b ^= a ^= b ^= a %= b);
    return a;
}
int main() {
    int count = 0;
    for (int i = 1; i <= 1024; i++) {
        for (int j = 1; j <= 1024; j++) {
            if (gcd(i, j) == 1 && i != j) {
                count += 2;
            } else if (gcd(i, j) == 1 && i == j) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}