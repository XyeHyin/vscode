#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    if(a==b){
        cout << a * a/2-a/2 << endl;
        return 0;
    
    }else{
    double s= (a * b) / 2.0;
    int ans = s + 0.5;
    cout << ans<< endl;
    }
    return 0;
}