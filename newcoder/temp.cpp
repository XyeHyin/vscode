#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    while(n--){
        int s;
        cin >> s;
        if((int)sqrt(s)*(int)sqrt(s) == s){
            cout << "0" << endl;
            }
        else{
            cout << "3" << endl;
        }
    }
    return 0;
}