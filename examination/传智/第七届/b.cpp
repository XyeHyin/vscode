#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if(!(x&1)){
            cout << x << endl;
            continue;
        }
        string s = to_string(x);
        vector<int> dic(10, 0);
        for (int i = 0; i < s.size();i++){
            dic[s[i] - '0']++;
        }
    }
}