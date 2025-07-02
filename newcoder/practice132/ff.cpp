#include <bits/stdc++.h>
using namespace std;

int main() {
    int limit;
    cout << "请输入生成勾股数的上限: ";
    cin >> limit;
    cout << "a\tb\tc\n";
    for (int a = 1; a <= limit; a++) {
        for (int b = a; b <= limit; b++) {
            double c = sqrt(a * a + b * b);
            if (c == floor(c) && c <= limit) {
                cout << a << "\t" << b << "\t" << (int)c << "\n";
            }
        }
    }
    return 0;
}