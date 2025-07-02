#include <bits/stdc++.h>
using namespace std;
#define int long long
//1,3,9,27一定是最优砝码
signed main(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    vector<int> a;
    a.push_back(1);
    for (int i = 1;;i++){
         a.push_back(a.back() * 3+1);
         if(a.back() >= n){
             cout << i+1 << endl;
             return 0;
         }
    }
        return 0;
}