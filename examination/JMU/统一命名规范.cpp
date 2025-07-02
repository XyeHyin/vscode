#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n;i++){
        string str;
        cin >> str;
        if(s=="Camel"){
            if(isupper(str[0])) cout << (char)tolower(str[0]);
            else cout << str[0];
            for (int i = 1;i<str.size();i++){
                if(str[i]=='_'){
                    i++;
                    cout << (char)toupper(str[i]);
                }else{
                    cout << str[i];
                }
            }
        }else if(s=="Pascal"){
            if (isupper(str[0]))cout << str[0];
            else cout << (char)toupper(str[0]);
           for(int i=1;i<str.size();i++){
               if(str[i]=='_'){
                   i++;
                   cout << (char)toupper(str[i]);
           }else{
                cout << str[i];
           }
           }
        }else if(s=="Snake"){
            for (int i = 0; i < str.size();i++){
                if(isupper(str[i])){
                    if(i!=0)
                        cout << "_";
                    cout<<(char)tolower(str[i]);
                    }
                else cout << str[i];
            }
        }
        cout << endl;
    }
}