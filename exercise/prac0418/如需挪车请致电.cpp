#include <bits/stdc++.h>
using namespace std;
string dic[10]={"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int main(){
    string ans = "";
    for (int i = 0; i < 11;i++){
        string s;
        cin >> s;
        if(isdigit(s[0])){
            char fuhao;
            int weizhi;
            bool flag = false;
            for (int j = 0;j<s.size();j++){
                if(!isdigit(s[j])) {
                    fuhao = s[j];
                    weizhi = j;
                    flag = true;
                    break;
                }
            }
            if(!flag)ans += s; continue;
            if(fuhao=='+') ans+= to_string(stoi(s.substr(0, weizhi)) + stoi(s.substr(weizhi + 1, s.size() - weizhi - 1)));
        else if(fuhao=='-')ans += to_string(stoi(s.substr(0, weizhi)) - stoi(s.substr(weizhi + 1, s.size() - weizhi - 1)));
        else if(fuhao=='/') ans += to_string(stoi(s.substr(0, weizhi)) / stoi(s.substr(weizhi + 1, s.size() - weizhi - 1)));
        else if (fuhao == '*') ans += to_string(stoi(s.substr(0, weizhi)) * stoi(s.substr(weizhi + 1, s.size() - weizhi - 1)));
        else if (fuhao == '%')ans += to_string(stoi(s.substr(0, weizhi)) % stoi(s.substr(weizhi + 1, s.size() - weizhi - 1)));
        else if(fuhao=='^')ans+= to_string((int)pow(stoi(s.substr(0, weizhi)), stoi(s.substr(weizhi + 1, s.size() - weizhi - 1))));
    }
    if(s.substr(0,4)== "sqrt")ans+= to_string((int)sqrt(stoi(s.substr(4, s.size() - 4))));
    for(int j=0;j<10;j++){
        if(dic[j]==s.substr(0,s.size()))
            ans += to_string(j);
    }
}
cout << ans << endl;
}