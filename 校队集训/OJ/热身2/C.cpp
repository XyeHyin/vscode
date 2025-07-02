#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    stack<char> a;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            a.push(s[i]);
        } else {
            if (a.empty()) {
                cout << "false" << endl;
                return 0;
            }
            if (s[i] == ')' && a.top() == '(') {
                a.pop();
            } else if (s[i] == ']' && a.top() == '[') {
                a.pop();
            } else if (s[i] == '}' && a.top() == '{') {
                a.pop();
            }
        }
    }
    if (a.empty()) {
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    return 0;
}