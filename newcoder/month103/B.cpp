#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        string s;
        getline(cin, s);
        auto pos = s.find('@');
        if (pos == string::npos) {
            cout << "No" << endl;
            continue;
        }
        string a = s.substr(0, pos);
        string b = s.substr(pos + 1);
        bool flag =!a.empty() && a.size() <= 64 && a.front() != '.' && a.back() != '.';
        for (int i = 0; i < a.size(); i++) {
            if (!isalnum(a[i]) && a[i] != '.') {
                flag = 0;
                break;
            }
        }
        bool flag2 = !b.empty() && b.size() <= 255 && b.front() != '.' &&b.back() != '.' && b.front() != '-' && b.back() != '-';
        for (int i = 0; i < b.size(); i++) {
            if (!isalnum(b[i]) && b[i] != '.' && b[i] != '-') {
                flag2 = 0;
                break;
            }
        }
        if (flag && flag2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}