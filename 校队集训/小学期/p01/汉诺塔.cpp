#include <bits/stdc++.h>
using namespace std;
void  f(int n,char a ,char b , char c){
    if(n<=0) return;
    f(n - 1, a, c, b);
    cout<<a<<"->"<<c<<endl;
    f(n - 1, b, a, c);
 }
int main(){
    f(3,'A','B','C');
    return 0;
}