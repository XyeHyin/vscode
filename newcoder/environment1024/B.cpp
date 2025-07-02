#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
       int  x;
        cin >> x;
        int tmp = x * x * x * x;
        bitset<128> b(tmp);
        string ans = b.to_string();
        ans.erase(0, ans.find_first_not_of('0'));
        cout << ans << endl;
    }
    return 0;
}