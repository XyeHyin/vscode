#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int sum = 6 - max(n, m)+1;
    if(sum==1){
        cout << "0/1";
        return 0;
    }
    if(sum==6){
        cout << "1/1";
        return 0;
    }
    cout<<sum/__gcd(sum, 6)<<"/"<<6/__gcd(sum, 6)<<endl;
}