#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c, d, ans,hour,minute;
    cin >> a >> b >> c >> d;
    ans = (c * 60 + d) - (a * 60 + b);
    hour = ans / 60;
    minute = ans % 60;
    cout << hour << " " << minute << endl;
}