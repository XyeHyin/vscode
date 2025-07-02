#include <bits/stdc++.h>
using namespace std;
void f(int *a,int n){
    if(n==0) return;
    f(a+1, n - 1);
    cout << a[0] << " ";
}
int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,0};
    f(a,10);
    return 0;
}