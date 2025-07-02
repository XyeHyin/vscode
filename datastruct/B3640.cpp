#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    stringstream ss;
    getline(cin, s);
    ss << s;
    vector<string> v;
    while(ss >>s){
        if(islower(s[0])){
            for(int i = 0; i < s.size(); i++){
                if(islower(s[i])){
                    s[i] = toupper(s[i]);
                }
            }
        }else if(isupper(s[0])){
            for(int i = 0; i < s.size(); i++){
                if(isupper(s[i])){
                    s[i] = tolower(s[i]);
                }
            }
        }else if(isdigit(s[0])){
            reverse(s.begin(), s.end());
        }
        v.push_back(s);
    }
    for(int i=v.size()-1; i>=0; i--){
        cout << v[i] << " ";
    }
    return 0;
}