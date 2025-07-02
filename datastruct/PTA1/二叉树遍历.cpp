#include <bits/stdc++.h>
using namespace std;
string a, b;
void build(int l1, int l2, int r1, int r2) {
    if (l1 > l2) return;
    char root =' ';
    int pos = -1;
    for (int i = r1; i <= r2; i++) {
        for (int j = l1; j <= l2; j++) {
            if (b[i] == a[j]) {
                root = b[i];
                pos = j;
                break;
            }
        }
        if (root != ' ')
            break;
    }
    cout << root;
    build(l1, pos - 1, r1, r2);
    build(pos + 1, l2, r1, r2);
}
int main() {
    cin >> a >> b;
    build(0, a.size() - 1, 0, b.size() - 1);
    cout << endl;
    return 0;
}