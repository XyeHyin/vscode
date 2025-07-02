#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    while (b ^= a ^= b ^= a %= b)
        ;
    return a;
}
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << gcd(gcd(a, b), c) << endl;
}