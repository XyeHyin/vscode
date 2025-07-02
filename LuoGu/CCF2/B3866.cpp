#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int cnt = 0;
    while(1){
        if(s=="495") break;
        sort(s.begin(), s.end());
        int mn=stoi(s);
        reverse(s.begin(), s.end());
        int mx=stoi(s);
        s=to_string(mx-mn);
        cnt++;
    }
    cout << cnt;
    return 0;
}