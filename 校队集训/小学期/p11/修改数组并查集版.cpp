#include <bits/stdc++.h>
using namespace std;
int father[100000];
int findFather(int x) {
    if (father[x] == 0) {
        father[x] = x + 1;
        return x;
    } else {
        return father[x] = findFather(father[x]);
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(1000000, 0);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cout << findFather(x) << " ";
    }

    return 0;
}