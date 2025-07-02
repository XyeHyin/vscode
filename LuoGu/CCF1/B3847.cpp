#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c;
    char d;
    cin >> a >> b >> c >> d;
    int ans=0;
    if(d=='P')
        ans += 60 * 60 * 12;
        ans+=a*60*60+b*60+c;
    cout << ans << endl;
    return 0;
}