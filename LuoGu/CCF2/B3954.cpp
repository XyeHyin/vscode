#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int mul = 1;
    while(n--){
        int a;
        cin>>a;
        mul *= a;
        if (mul > 1000000) {
            cout << ">1000000"<<endl;
            return 0;
        }
    }
    cout << mul << endl;
    return 0;
}