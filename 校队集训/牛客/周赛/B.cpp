#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll m = n;
    int count1 = 0,count2=0;
    ll temp=sqrt(n),temp2=sqrt(m);
    while(temp*temp!=n){
        n += 2;
        count1++;
        temp = sqrt(n);
    }
    while(temp2*temp2!=m){
        m -= 2;
        count2++;
        temp2 = sqrt(m);
    }
   cout<<min(count1,count2)<<endl;
    return 0;
}