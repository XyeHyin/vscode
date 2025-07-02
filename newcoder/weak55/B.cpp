#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    int temp = 1;
    int cnt = 0;
    while(n--){
        int cc;
        cin>>cc;
        temp *= cc; 
        if(temp % 10 == 6){
            cnt++;
        }
        string a = to_string(temp);
        if(a.size() > 1){
            temp = a[a.size() - 2] - '0';
            temp = temp * 10 + a[a.size() - 1] - '0';
        }
      }
    cout << cnt << endl;
    return 0;
}