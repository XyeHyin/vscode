#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    auto it=s.find_first_not_of("0",'.');
    if(it==string::npos){
        cout << 0;
        return 0;
    }
    int ans=s.size();
    s=s.substr(it);
    cout << ans - s.size()+1;

    return 0;
}