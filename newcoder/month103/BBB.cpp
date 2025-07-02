#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solve(const string &s) {
    if (s.find('@') == string::npos) {
        return false;
    }
    if (count(s.begin(), s.end(), '@') > 1) {
        return false;
    }
    vector<string> c;
    size_t pos = s.find('@');
    c.push_back(s.substr(0, pos));
    c.push_back(s.substr(pos + 1));
    if (c.size() != 2) {
        return false;
    }
    string a = c[0], b = c[1];
    if (a.length() <= 0 || a.length() > 64 || b.length() <= 0 ||
        b.length() > 225) {
        return false;
    }
    if (a[0] == '.' || a[a.length() - 1] == '.' || b[0] == '-' ||
        b[b.length() - 1] == '-' || b[0] == '.' || b[b.length() - 1] == '.') {
        return false;
    }
    for (char i : a) {
        if (!isalnum(i) && i != '.') {
            return false;
        }
    }
    for (char i : b) {
        if (!isalnum(i) && i != '.' && i != '-') {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        if (solve(s)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}