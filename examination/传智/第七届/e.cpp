#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n";
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, x;
    cin >> n >> k >> x;
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    while (k--) {
        int tmp = q.top();
        q.pop();
        tmp -= x;
        while(!q.empty()&&tmp>q.top()){
            tmp -= x;
            k--;
        }
        q.push(tmp);
    }
    cout << q.top() << endl;
    return 0;
}