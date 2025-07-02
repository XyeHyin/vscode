#include <bits/stdc++.h>
using namespace std;
const int mod = 200005;
int add[mod], gett[mod];
int main() {
    int m, n;
    cin >> m >> n;
    priority_queue<int, vector<int>, greater<int>> xiao;
    priority_queue<int, vector<int>> da;
    for (int i = 0; i < m; i++) {
        cin >> add[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> gett[i];
    }
    int j = -1;
    for (int i = 0; i < n; i++) {
        while (j < gett[i] - 1) {
            da.push(add[++j]);
            xiao.push(da.top());
            da.pop();
        }
        cout << xiao.top() << endl;
        da.push(xiao.top());
        xiao.pop();
    }
    return 0;
}