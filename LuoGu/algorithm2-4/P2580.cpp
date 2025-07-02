#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    set<string> dic;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        dic.insert(s);
    }
    int nn;
    cin >> nn;
    set<string> ans;
    for(int i = 0; i < nn; i++){
        string s;
        cin >> s;
        if(ans.find(s) != ans.end()){
            cout<<"REPEAT"<<endl;
            continue;
        }else{
            ans.insert(s);
        }
        if(dic.find(s) != dic.end()){
            cout << "OK" << endl;
        }else{
            cout << "WRONG" << endl;
        }
    }
    return 0;
}