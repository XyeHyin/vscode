#include <iostream>
using namespace std;
int main() {
    int h, m, s, t;
    cin >> h >> m >> s >> t;
    cout << (h + (m + (s + t) / 60) / 60) % 24<< ' ' << (m + (s + t) / 60) % 60 << ' ' << (s + t) % 60 << '\n';
}