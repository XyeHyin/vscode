#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin >> n>>m;
    queue<int> a;
    for (int i = 1; i <= n; i++) {
        a.push(i);
    }
    int j = 1;
    while (a.size() != 0) {
        if (j % m == 0) {
            cout << a.front() << " ";
            a.pop();
            j++;
        } else {
            a.push(a.front());
            a.pop();
            j++;
        }
    }

    return 0;
}