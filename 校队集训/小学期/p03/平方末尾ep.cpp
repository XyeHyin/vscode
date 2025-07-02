#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a(100,0);
    set<int> se;
    for(int i=0;i<100;i++){
        a[i]=pow(i,2);
    }
    for(int i=4;i<100;i++){
        string s=to_string(a[i]);
        se.insert(stoi(s.substr(s.size()-2,2)));
    }
    cout<<se.size();

    return 0;
}