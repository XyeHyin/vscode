#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    string ch="";
    if(s[0]=='-'){
        ch+="-";
        s.erase(0,1);
    }
    reverse(s.begin(),s.end());
       while (true){
        if(s[0]!='0') break;
        s.erase(0,1);   
    }
    if(s.size()==0) cout<<0<<endl;
    else cout<<ch<<s<<endl;
    return 0;
}