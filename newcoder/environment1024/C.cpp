#include <bits/stdc++.h>
using namespace std;
int main(){
    while(true){
        string s;
        cin >> s;
        if(s=="-1")break;
        bool ou = 0;
        if (s[s.size() - 1] - '0' % 2 == 0||s[s.size() - 1] == '0') {
            ou = 1;
        }
        if(ou)cout << "1" << endl;
        else cout << "-1" << endl;
    }
    return 0;
}