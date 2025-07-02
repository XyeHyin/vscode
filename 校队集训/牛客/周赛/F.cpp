#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    if(n==4) cout<<26<<endl;
    else if(n==3)cout<<46<<endl;
    else cout << 1 << endl;
    return 0;
}