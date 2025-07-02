#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    Xunhuan:
    while(cin>>s){
        if (s == "End of file"){
            return 0;
        }
        vector<int> pot;
        for (int i = 0; i < s.size();i++){
            if(isalpha(s[i])||s[i]=='-'){
                cout << 'N' << endl;
                goto Xunhuan;
            }
            if(s[i]=='.'){
                pot.push_back(i);
            }
            
        }
        if(pot.size()!=3){
            cout << 'N' << endl;
            goto Xunhuan;
        }
        if((s.substr(0,pot[0]))>"255"||(s.substr(pot[0],pot[1]-pot[0]))>"255"||(s.substr(pot[1],pot[2]-pot[1]))>"255"||(s.substr(pot[2],s.size()-pot[2]))>"255"){ 
            cout << 'N' << endl;
            goto Xunhuan;
        }
        cout << 'Y' << endl;
    }
}