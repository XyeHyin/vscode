#include <bits/stdc++.h>
using namespace std;
const int maxn=5e4+10;
map<string,string> father;
string findfather(string x){
    return father[x]==x?x:father[x]=findfather(father[x]);
}
int main(){
    string tmp;
    while(true){
        char c;
        string s;
        cin >> c;
        if(c=='$') break;
        cin >> s;
        if(c=='#'){
            tmp=s;
            if(father[tmp]=="") father[tmp]=tmp;
        }else if(c=='+'){
            father[s]=tmp;
        }else if(c=='?'){
            cout << s << " " << findfather(s) << endl;
        }
    }
    return 0;
}