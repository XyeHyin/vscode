#include <bits/stdc++.h>
using namespace std;
int main(){
    double n;
    cin >> n;
    for (int i = 1;;i++){
        for (int j = 1;j<=i;j++){
            double tmp = round((1.0 * j / i) * 10000) * 1.0 / 100;
            if (tmp == n){
                cout << i << endl;
                return 0;
            }else if (tmp > n){
                break;
            }
        }
    }
        return 0;
}