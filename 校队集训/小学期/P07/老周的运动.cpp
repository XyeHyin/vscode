#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int x, y;
    x = (n + 1) / 2;
    if(x%2==0) x = -x;
    y = (n + 2) / 4 * 2;
    if((n+2)%4>=2) y = -y;
    cout<<x<<" "<<y<<endl;
    return 0;
}