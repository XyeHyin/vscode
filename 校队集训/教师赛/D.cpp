#include <bits/stdc++.h>
using namespace std;
string dic = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string operator*(string &s, int n) {
    string res;
    while (n--) {
        res += s;
    }
    return res;
}
int main() {
    int _;
    cin >> _;
    while (_--) {
        int m, k;
        cin >> m >> k;
        string s;
        s = dic.substr(0, m);
        s = s * k;
        while (s.size() > 1) {
            string temp = "";
            for (int i = 1; i < s.size(); i += 2) {
                temp += s[i];
            }
            s = temp;
        }
        cout << s << endl;
    }
    return 0;
}