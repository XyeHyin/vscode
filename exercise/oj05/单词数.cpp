#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while (getline(cin, s)){
        if (s == "#"){
            break;
        }
        vector<string> ans;
        vector<int> blank;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' '&&s[i-1]!=' '){
                blank.push_back(i);
            }
        }
        bool flag = false;
        string temp = s.substr(0, blank[0]);
        ans.push_back(temp);
        for (int i = 1; i < blank.size(); i++){
            string temp = s.substr(blank[i - 1] + 1, blank[i] - blank[i - 1] - 1);
            flag = false;
            for (int j = 0; j < ans.size(); j++) {
                if (ans[j] == temp) {
                    flag = true;
                    break;
                }
            }
            if (!flag) ans.push_back(temp); 
        }
        flag = false;
        temp = s.substr(blank[blank.size() - 1] + 1, s.size() - blank[blank.size() - 1] - 1);
        for (int i = 0; i < ans.size(); i++){
            if (ans[i] == temp){
                flag = true;
                break;
            }}
        if (!flag) {   
             ans.push_back(temp);
        }
        if(s[0]!=' ') cout << ans.size() << endl;
        else cout << ans.size() - 1 << endl;
    }
}