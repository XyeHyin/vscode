#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> s1 = {"a", "b", "c", "d", "e", "f", "g", "h", "i",
                         "j", "k", "l", "m", "n", "o", "p", "q", "r",
                         "s", "t", "u", "v", "w", "x", "y", "z"};
    vector<string> s2 = {"s", "u", "w", "y", "a", "c", "e", "g", "i",
                         "k", "m", "o", "q", "r", "t", "v", "x", "z",
                         "b", "d", "f", "h", "j", "l", "n", "p"};
    cout << "请选择要加密还是要解密,加密请输入0,解密请输入1" << endl;
    int n;
    cin >> n;
    cout << "请输入要加密或解密的字符串" << endl;
    string s, ans;
    cin >> s;
    if (n == 0) {
        for (int i = 0; s[i]; i++) {
            for (int j = 0; j < 26; j++) {
                if (s[i] == s1[j][0]) {
                    ans += s2[j];
                }
            }
        }
    } else if (n == 1) {
        for (int i = 0; s[i]; i++) {
            for (int j = 0; j < 26; j++) {
                if (s[i] == s2[j][0]) {
                    ans += s1[j];
                }
            }
        }
    }
    cout << "结果为：" << endl << ans << endl;
    return 0;
}