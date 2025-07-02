#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        min(a + d, b + c) % 2 == 0 ? cout << "yukari" << endl
                                   : cout << "kou" << endl;
    }

    return 0;
}