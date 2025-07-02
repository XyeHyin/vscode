#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> records(n);
    for (int i = 0; i < n; ++i) {
        int type, price, time;
        cin >> type >> price >> time;
        records[i] = make_tuple(type, price, time);
    }
    queue<pair<int, int>> coupons;
    int total_cost = 0;
    for (const auto &record : records) {
        int type, price, time;
        tie(type, price, time) = record;
        if (type == 0) {
            total_cost += price;
            coupons.push({price, time + 55});
        } else {
            while (!coupons.empty() && coupons.front().second < time) {
                coupons.pop();
            }
            if (!coupons.empty() && coupons.front().first >= price) {
                coupons.pop();
            } else {
                total_cost += price;
            }
        }
    }

    cout << total_cost << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}