#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int sum = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
        sum += x;
    }
    if(q.size()==1){
        cout << q.top() + k << endl;
        return;
    }
    sum = (sum + k) / n;
    k += m;
    int flag = 0;
    int ans = 0;
    while (!q.empty() && k) {
        int tp = q.top();
        q.pop();
        q.push(tp + 1);
        k--;
    }
    cout << q.top() << endl;
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
