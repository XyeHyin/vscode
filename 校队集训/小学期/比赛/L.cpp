#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    if(a==1||b==1){
        cout << "hlyyds!!!" << endl;
    }else if (a % 2 == 0 && b % 2 == 0) {
        cout << "xbyyds!!!" << endl;
    } else if (a % 2 != 0 && b % 2 != 0) {
        cout << "xbyyds!!!" << endl;
    } else {
        cout << "hlyyds!!!" << endl;
    }

    return 0;
}