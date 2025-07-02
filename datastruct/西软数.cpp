#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    string n;
    int k;
    cin >> n >> k;
    k--;
    int ans = 0;
    string res = "";
    for (int i = n.size() - 1; i >= 0; i--) {
        res += (k % (n[i] - '0' + 1)) + '0';
        k /= (n[i] - '0' + 1);
    }
    reverse(res.begin(), res.end());
    cout << stoll(res) << endl;
    return 0;
}