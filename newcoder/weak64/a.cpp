#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    if(s=="yes"||s=="no") cout << "accept" << endl;
    else cout << "wrong answer" << endl;
    return 0;
}