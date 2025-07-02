#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans=d-(2*a+5*b+3*c);
    if(ans>=0){
        cout << "Yes"<< endl;
    }else{
        cout << "No" << endl;
    }
    cout<<abs(ans)<<endl;
    return 0;
}