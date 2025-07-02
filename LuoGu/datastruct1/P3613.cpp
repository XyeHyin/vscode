#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    map<vector<int>,int> mp;
    for(int i = 0; i < q; i++){
        int a;
        cin >> a;
        if(a==1){
            int b, c, d;
            cin >> b >> c >> d;
            mp[{b,c}] = d;
        }else{
            int b, c;
            cin >> b >> c;
            cout << mp[{b,c}] << endl;
        }

    }
    return 0;
}