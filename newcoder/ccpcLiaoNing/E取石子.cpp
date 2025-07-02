#include <bits/stdc++.h>
using namespace std;
int main() {
    int _;
    cin >> _;
    while (_--) {
        int a, b, n;
        cin >> a >> b >> n;
        cout << (n & 1 ? "Alice" : "Bob") << endl;
    }
    return 0;
}