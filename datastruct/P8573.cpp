#include <bits/stdc++.h>
using namespace std;
int main() {
    bool big = 0;
    int n;
    cin >> n;
    map<string, int> mp;
    while (n--) {
        string s;
        cin >> s;
        if (s == "CapsLock") {
            big = !big;
        } else {
            mp[s] = big;
        }
    }
    int _;
    cin >> _;
    for (int k = 0; k < _; k++) {
        int a;
        cin >> a;
        a %= mp.size();
        if (big && k % 2 == 1) {
            int j = 0;
            for (auto i : mp) {
                if (j == a) {
                    if (i.second) {
                        cout << i.first << endl;
                        break;
                    } else {
                        for (int k = 0; k < i.first.size(); k++) {
                            if (isupper(i.first[k]))
                                cout << (char)tolower(i.first[k]);
                            else
                                cout << (char)toupper(i.first[k]);
                        }
                        cout << endl;
                    }
                }
                j++;
            }
        } else {
            int j = 0;
            for (auto i : mp) {
                if (j == a) {
                    if (i.second) {
                        for (int k = 0; k < i.first.size(); k++) {
                            if (isupper(i.first[k]))
                                cout << (char)tolower(i.first[k]);
                            else
                                cout << (char)toupper(i.first[k]);
                        }
                        cout << endl;
                    } else {
                        cout << i.first << endl;
                        break;
                    }
                }
                j++;
            }
        }
    }
    return 0;
}