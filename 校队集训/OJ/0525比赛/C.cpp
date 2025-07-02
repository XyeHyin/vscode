#include <bits/stdc++.h>
using namespace std;
int main(){
    double A, B, H;
    while(cin >> A >> B >> H){
        double ans = 0;
        ans += A * B * 4;
        ans += B*sqrt((H-A) * (H-A) + (B/2) * (B/2))*2;
        printf("%.3f\n", ans);
    }
}