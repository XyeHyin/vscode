#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < s.length();i++){
        if(s[i]+n>'z'){
            s[i]=s[i]+n-26;
        }else{
            s[i]=s[i]+n;
        }
    }
    cout << s << endl;
}