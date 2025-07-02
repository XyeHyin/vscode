#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int maxn = max(a, max(b, c));
    int ans = 0;
    if(a == maxn) ans=max(b+c, a);
    else if(b == maxn) ans=max(a+c, b);
    else ans=max(a+b, c);
    cout << ans << endl;
    return 0;
}