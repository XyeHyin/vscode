#include <bits/stdc++.h>
using namespace std;
int main() { 
    long long sum = 0,count=0,n;
while(cin>>n){
    sum+=n;
    count++;
}
cout<<sum*(1ll<<count-1);
    return 0;
}