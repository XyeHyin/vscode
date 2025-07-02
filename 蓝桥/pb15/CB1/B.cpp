#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
signed main()
{
  int n;
  double d;
  cin>>n>>d;
  int zheng=d;
  zheng*=(1<<n);
  int xiao=((int)(d*100))%100;
  xiao*=(1<<n);
  double xx=round(xiao/100.0);
  cout<<zheng+xx<<endl;
  return 0;
}