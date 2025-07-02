#include <bits/stdc++.h>
using namespace std;
int main(){
    int _;
    cin >> _;
    while(_--){
        string s;
        cin >> s;
        int len = s.length();
        int cnt = 0;
        for (int i = 0; i < len;i++){
            cnt+=pow(s[i]-'0', len) ;    
        }
        if(to_string(cnt)==s){
            cout << "T" << endl;
        }else{
            cout << "F" << endl;
        }
    }
    return 0;
}