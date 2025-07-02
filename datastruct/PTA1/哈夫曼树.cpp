#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        q.push(a);
    }
    int ans = 0;
    while (q.size() > 1) {
        int aa = q.top();
        q.pop();
        int bb = q.top();
        q.pop();
        int sum = aa + bb;
        ans += sum;
        q.push(sum);
    }
    cout << ans << endl;
    return 0;
}