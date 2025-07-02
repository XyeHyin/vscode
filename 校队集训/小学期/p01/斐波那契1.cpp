#include <bits/stdc++.h>
using namespace std;
int fib(int n,int a,int b){
    if(n==0) return a;
    if(n==1) return b;
    return fib(n-1,b,a+b);

}
int main(){
    cout << fib(40, 0, 1);
    return 0;
}