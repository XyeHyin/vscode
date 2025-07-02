#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("data1.in", "w", stdout);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n = uniform_int_distribution<int>(1, 2000)(rng);
    ll m = uniform_int_distribution<ll>(1, 100000LL)(rng);
    string letters = "abcdefghijklmnopqrstuvwxyz";
    string s;
    s.resize(n);
    for (int i = 0; i < n; i++) {
        s[i] = letters[uniform_int_distribution<int>(0, 25)(rng)];
    }
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cost[i] = uniform_int_distribution<int>(1, 1000000)(rng);
    }
    cout << n << " " << m << "\n";
    cout << s << "\n";
    for (int i = 0; i < n; i++) {
        cout << cost[i] << (i + 1 == n ? "\n" : " ");
    }

    return 0;
}