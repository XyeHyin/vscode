#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
       if(s[i]=='.') cout << 0;
       else if(s[i]=='-'){
            if(s[i+1]=='.'){
                cout << 1;
                i++;
                }else { 
                    cout << 2;
                    i++;
               }
           }
    }
    cout << endl;
    return 0;
}