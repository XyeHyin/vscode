#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    cout << n << endl << "=" << n << "^1" << endl;
    vector<pair<int, int>> ans;
    for (int a = 2; a <= sqrt(n); a++) {
        int tmp = a;
        int b = 1;
        while (tmp <= n) {
            tmp *= a;
            b++;
            if (tmp == n) {
                ans.push_back({a, b});
            }
        }
    }
    sort(ans.begin(), ans.end(),
         [](pair<int, int> a,  pair<int, int> b) {
             return a.second < b.second;
         });
    for (auto i : ans) {
        cout << "=" << i.first << "^" << i.second << endl;
    }
    return 0;
}