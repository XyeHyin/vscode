#include <bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    cin >> s1 >> s2;
    long long ss1=1, ss2=1;
    for (int i = 0;i<s1.length();i++){
        ss1 *= s1[i] - 'A' + 1;
    }
    for (int i = 0;i<s2.length();i++){
        ss2 *= s2[i] - 'A' + 1;
    }
    if(ss2%47==ss1%47) cout<<"GO";
    else cout<<"STAY";
        return 0;
}