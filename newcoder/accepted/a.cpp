#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0;i<s.size()-1;i++) {
           if(s[i]=='1')s[i+1]='0';
        }
        cout << count(s.begin(), s.end(), '1') << endl;
    }
    return 0;
}