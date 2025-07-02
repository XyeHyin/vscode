#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i]!=' ') {
            count++;
        }
    }
    cout << count;
    return 0;
}