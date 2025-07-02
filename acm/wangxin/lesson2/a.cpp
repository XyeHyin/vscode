#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    set<char> se;
    for (int i = 0; i < s.size(); i++){
        se.insert(s[i]);
    }
    if(se.size() & 1){
        cout << "YI! WU!" << endl;
        return 0;
    }else{
        cout<<"CLEAN!"<<endl;
    }
    return 0;
}