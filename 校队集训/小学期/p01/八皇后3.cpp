#include <bits/stdc++.h>
using namespace std;

struct State {
    int x, y;
    int a[20][20];
};

int cnt = 0;

bool check(int a[20][20], int n, int x, int y) {
    for (int i = 0; i < x; i++) {
        if (a[i][y] == 1 || (y - x + i >= 0 && a[i][y - x + i] == 1) ||
            (y + x - i < n && a[i][y + x - i] == 1)) {
            return false;
        }
    }
    return true;
}

void f(int n) {
    stack<State> s;
    State ini = {0, 0, {}};
    s.push(ini);

    while (!s.empty()) {
        State cur = s.top();
        s.pop();

        if (cur.x == n) {
            cnt++;
            continue;
        }

        for (int y = 0; y < n; y++) {
            if (check(cur.a, n, cur.x, y)) {
                State state = cur;
                state.a[cur.x][y] = 1;
                state.x++;
                s.push(state);
                // state.a[cur.x][y] =0;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    f(n);
    cout << cnt;
    return 0;
}