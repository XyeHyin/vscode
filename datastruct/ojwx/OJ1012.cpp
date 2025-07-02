#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cin.ignore();
    string s;
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        cout << s << endl<<endl;
    }
    while (getline(cin, s)) {
        stringstream ss(s);
        string sss;
        while (ss >> sss) {
            cout << sss << endl<<endl;
        }
    }
    return 0;
}