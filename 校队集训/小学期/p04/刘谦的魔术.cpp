#include <bits/stdc++.h>
using namespace std;
string dic = "JQKAJQKA";
int main() {
    int m;
    cin >> m;
    while (m--) {
        queue<int> q;
        for (int i = 0; i < 8; i++) {
            q.push(i);
        }
        int n, a, x;
        cin >> n >> a >> x;
        for (int i = 0; i < n; i++) {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        q.pop();
        q.pop();
        q.pop();
        cout << dic[q.front()] << endl;
    }
    return 0;
}