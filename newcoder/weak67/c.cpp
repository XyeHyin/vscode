#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string n, c;
    cin >> n >> c;
    int nn=stoi(n);
    nn -= 2;
    nn -=c.size();
    int cc=stoi(c);
    int cnt=0;
    for (int i = 0; i <= cc;i++){
       string tmpa=to_string(i);
       string tmpb=to_string(cc-i);
       if(tmpa.size()+tmpb.size()==nn){
              cnt++;
       }
    }
    cout << cnt << endl;
        return 0;
}