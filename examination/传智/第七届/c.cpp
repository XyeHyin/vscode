#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int tmpa = 0, tmpb = 0;
    for (int i = 0; i < s.size() - 2; i++) {
        if (s[i] == ':' && s[i + 1] == '-' && s[i + 2] == ')')tmpa++;
        if (s[i] == ':' && s[i + 1] == '-' && s[i + 2] == '(') tmpb++;
    }
    if (tmpa + tmpb == 0) cout << "None" << endl;
    else if (tmpa > tmpb)cout << "Happy" << endl;
    else if (tmpa == tmpb)cout << "Just so so" << endl;
    else cout << "Sad" << endl;
    return 0;
}