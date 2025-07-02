#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j==1||j==n||i==j){
                cout<<'+';
            }else
                cout << '-';
        }
        cout << endl;
    }
        return 0;
}