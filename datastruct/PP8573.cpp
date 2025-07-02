#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    bool big = 0;
    int n;
    cin >> n;
    vector<string> a;
    while (n--) {
        string s;
        cin >> s;
        if (s == "CapsLock") {
            big = !big;
        } else {
            if (big) {
                for (int i = 0; i < s.size(); i++) {
                    if (isupper(s[i])) {
                        s[i] = tolower(s[i]);
                    } else {
                        s[i] = toupper(s[i]);
                    }
                }
                a.push_back(s);
            } else {
                a.push_back(s);
            }
        }
    }
    int _;
    cin >> _;
    for (int i = 0; i < _; i++) {
        int x;
        cin >> x;
        int tmp = x;
        x--;
        tmp=x/(a.size());
        x %= (a.size());
        if (big) {
            if (tmp % 2 == 0) {
                cout << a[x] << endl;
                // cout << "第一个" << endl;
            } else {
                for (int j = 0; j < a[x].size(); j++) {
                    if (isupper(a[x][j])) {
                        cout << (char)tolower(a[x][j]);
                    } else {
                        cout << (char)toupper(a[x][j]);
                    }
                }
                cout << endl;
                // cout << "第二个" << endl;
            }
        } else {
            cout << a[x] << endl;
        }
    }

    return 0;
}