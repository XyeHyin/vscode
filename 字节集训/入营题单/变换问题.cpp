#include <iostream>
#include <string>
using namespace std;

string solution(string s, int k) {
    while(k--) {
        string ss="";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a') {
                ss += "bc";
            } else if(s[i] == 'b') {
                ss += "ca";
            } else {
                ss += "ab";
            }
        }
        s = ss;
    }
    return s;
    return "";
}

int main() {
    cout << (solution("abc", 2) == "caababbcbcca") << endl;
    cout << (solution("abca", 3) == "abbcbccabccacaabcaababbcabbcbcca") << endl;
    cout << (solution("cba", 1) == "abcabc") << endl;
    return 0;
}