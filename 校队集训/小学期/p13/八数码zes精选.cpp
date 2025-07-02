#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define ll long long
using namespace std;
const ll dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
const char moveDir[] = {'U', 'L', 'R', 'D'};
ll n;
map<ll, pair<ll, char>> m;

void printState(ll state) {
    vector<int> nums(9);
    for (int i = 8; i >= 0; --i) {
        nums[i] = state % 10;
        state /= 10;
    }
    for (int i = 0; i < 9; ++i) {
        cout << nums[i] << " ";
        if (i % 3 == 2)
            cout << endl;
    }
    cout << endl;
}

void printPath(ll end) {
    vector<ll> states;
    while (m[end].first != end) {
        states.push_back(end);
        end = m[end].first;
    }
    states.push_back(end);
    reverse(states.begin(), states.end());
    for (ll state : states) {
        printState(state);
    }
}

int main() {
    cin >> n;
    queue<ll> q;
    q.push(n);
    m[n] = {n, 'S'};
    while (!q.empty()) {
        ll u = q.front();
        ll c[3][3], f = 0, g = 0, n = u;
        q.pop();
        if (u == 123804765) {
            printPath(u);
            break;
        }
        for (ll i = 2; i >= 0; i--)
            for (ll j = 2; j >= 0; j--) {
                c[i][j] = n % 10, n /= 10;
                if (!c[i][j])
                    f = i, g = j;
            }
        for (ll i = 0; i < 4; i++) {
            ll nx = f + dx[i], ny = g + dy[i], ns = 0;
            if (nx < 0 || ny < 0 || nx > 2 || ny > 2)
                continue;
            swap(c[nx][ny], c[f][g]);
            for (ll i = 0; i < 3; i++)
                for (ll j = 0; j < 3; j++)
                    ns = ns * 10 + c[i][j];
            if (!m.count(ns)) {
                m[ns] = {u, moveDir[i]};
                q.push(ns);
            }
            swap(c[nx][ny], c[f][g]);
        }
    }
    return 0;
}