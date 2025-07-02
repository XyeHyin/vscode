#include <bits/stdc++.h>
using namespace std;
int main(){
    double n;
    cin>>n;
    double sum = 2;
    double step = 2;
    int i = 0;
    while(sum<n){
        step *= 0.98;
        sum += step;
        i++;
    }
    cout<<i+1<<endl;
    return 0;
}