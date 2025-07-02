#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    int counts[26] = {0}, countt[26] = {0};
    int puncting = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#' || s[i] == '!' || s[i] == '?') {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] == '#' || s[j] == '!' || s[j] == '?') {
                    puncting = j - i-1;
                    break;
                }
            }
        }
        if (isalpha(s[i])) {
            counts[tolower(s[i]) - 'a']++;
        }
    }
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '#' || t[i] == '!' || t[i] == '?') {
            for (int j = i + 1; j < t.size(); j++) {
                if (t[j] == '#' || t[j] == '!' || t[j] == '?') {
                    puncting = j - i-1;
                    break;
                }
            }
        }
        if (isalpha(t[i])) {
            countt[tolower(t[i]) - 'a']++;
        }
    }
    int anss = 0,anst = 0;
    for (int i = 0; i < 26; i++) {
        if (counts[i] - countt[i]<0) {
            anss++;
        }
        if (countt[i] - counts[i]<0) {
            anst++;
        }
    }
    if(anss==puncting&&anst==puncting) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}