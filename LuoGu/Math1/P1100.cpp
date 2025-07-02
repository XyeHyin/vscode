#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    bitset<32> b(n);
    bitset<32> c((b.to_ulong() >> 16) | (b.to_ulong() << 16));
    cout << c.to_ulong() << endl;
    return 0;
}