#include <bits/stdc++.h>
using namespace std;
int main(){
    for (int i = 0; i < 10;i++){
        for (int j = 0; j < 16;j++){
            for (int k = 0; k < 2;k++){
                int a;
                cin >> a;
                cout<<bitset<8>(a)<<" ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }
    // unsigned long long ans = 1;
    // for (int i = 0; i < 9;i++){
    //     ans *= 9;
    // }
    // cout << ans << endl;
    return 0;
}