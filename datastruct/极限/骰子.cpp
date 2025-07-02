#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int fenzi=6-max(a,b)+1;
    int fenmu=6;
    int g=__gcd(fenzi,fenmu);
    cout<<fenzi/g<<"/"<<fenmu/g<<endl;
    return 0;
}