#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0 || j == n - 1) {
                cout << "|";
            } else if (i == n / 2 || i == 0 || i == n - 1) {
                cout << "-";
            } else {
                cout << "x";
            }
        }
        cout << endl;
    }
    return 0;
}