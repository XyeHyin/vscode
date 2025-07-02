#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    string n;
    int k;
    cin >> n >> k;
    k--;
    int ans = 0;
    string res="";
    for(int i=0;i<n.size();i++){
        res += (k % (n[i] - '0') + '0');
    }
    cout << stoll(res) << endl;
        return 0;
}