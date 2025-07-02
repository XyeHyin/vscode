#include <bits/stdc++.h>
using namespace std;
int main(){
    map<int,int> mp;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        mp[x]=i;
    }
    int m;
    cin >> m;
    while(m--){
        int q;
        cin >> q;
        if(mp.find(q)!=mp.end()){
            cout << mp[q] << endl;
        }else{
            cout << 0 << endl;
        }
    }
    return 0;
}