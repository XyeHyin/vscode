#include <bits/stdc++.h>
using namespace std;
int main(){
    double ans=0;
    vector<double> x(3), y(3);
    for (int i = 0; i < 3;i++){
        cin >> x[i] >> y[i];
    }
        ans+= sqrt(pow(x[1]-x[0],2)+pow(y[1]-y[0],2));
       ans += sqrt(pow(x[2] - x[0], 2) + pow(y[2] - y[0], 2));
         ans += sqrt(pow(x[2] - x[1], 2) + pow(y[2] - y[1], 2));
    printf("%.2f", ans);
    return 0;
}