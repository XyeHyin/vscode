#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int i = 0,cnt=0;
    for(int i=0;i<s.size();i++){
        if(s.substr(i,2)=="VK"){
            s.replace(i,2,"00");
            cnt++;
        }
    }
    if(s.find("VV")!=string::npos||s.find("KK")!=string::npos) cnt++;
    cout << cnt;
    return 0;
}