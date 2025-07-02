#include <bits/stdc++.h>
using namespace std;
int main() {
    int m;
    cin >> m;
    while (m--) {
        deque<char> q{'J', 'Q', 'K', 'A', 'J', 'Q', 'K', 'A'};
        int n, a, x;
        cin >> n >> a >> x;
        for (int i = 0; i < n; i++) {
            int t = q.front();
            q.pop_front();
            q.push_back(t);
        }
        q.pop_front();
        q.pop_front();
        q.pop_front();
        cout << q.front() << endl;
    }

    return 0;
}