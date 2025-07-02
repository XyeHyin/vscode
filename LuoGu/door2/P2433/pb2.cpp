#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int m, t, s,ans;
    cin >> m >> t >> s;
    if (t==0){
        cout << 0 << endl;
        return 0;
    }
    if(s/t>=m){
        cout << 0 << endl;
        return 0;
    }
    if(s%t==0){
        ans = m-s / t;
        cout << ans << endl;
    }else if(s%t!=0){
        ans = m - s / t - 1;
        cout << ans << endl;
    }
   
}