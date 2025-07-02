#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
signed main(){
    int n;
    cin >> n;
    while(n--){
        int x,y;
        cin >> x >> y;
        for (int i = 0; i <= x / 2;i++){
            int lcm = i * (x - i) / gcd(i, x - i);
            if(lcm==y){
                cout << i << " " << x - i << endl;
                break;
            }
        }
    }
    return 0;
}