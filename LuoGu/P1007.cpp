#include <bits/stdc++.h>
int main() {
    long long l, n, minn = -1,minnn=0x3f3f3f3f,maxxx=0,a[5005];
    std::cin >> l >> n;
    for (int i = 0; i < n; i++) std::cin>>a[i],minnn=std::min(minnn,a[i]),maxxx=std::max(maxxx,a[i]),minn=a[i]<=l/2?std::max(minn,a[i]):std::max(minn,l+1-a[i]);
    minn==-1?std::cout << "0"<<" "<<"0"<<std::endl:std::cout<<minn<<" "<< std::max(l-minnn+1,maxxx) << std::endl;
}