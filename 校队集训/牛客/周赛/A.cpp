#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n%2!=0){
        cout << -1 << endl;
        return 0;
    }
    cout<<n/2<<" "<<n/2<<endl;
}