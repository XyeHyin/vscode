#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);   
    a[0] = 0;
    a[1] = 1;
    for (int i = 1; i <= n; i++){
         a[i] =a[i-1]+i;
    }
    cout<<accumulate(a.begin(),a.end(),0)<<endl;
        return 0;
}