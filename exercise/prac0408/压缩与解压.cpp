#include <bits/stdc++.h>
using namespace std;
int main(){
    char c;
    cin >> c;
    string s, ans;
    getchar();
    getline(cin, s);
    if(c=='C'){
        for (int i = 0; i < s.size();i++){
            if(s[i+1]==s[i]){
                int count = 1;
                while(s[i+1]==s[i]){
                    count++;
                    i++;
                }
                ans += to_string(count);
                ans += s[i];
            }else{
                ans += s[i];
            }
        }
    }else if(c=='D'){
        for (int i = 0; i < s.size();i++){
            if(isdigit(s[i])){
                int count = 0;
                while(isdigit(s[i])){
                    count = count * 10 + s[i] - '0';
                    i++;
                }
                for (int j = 0; j < count;j++){
                    ans += s[i];
                }
            }else{
                ans += s[i];
            }
        }
    }
    cout << ans << endl;
}