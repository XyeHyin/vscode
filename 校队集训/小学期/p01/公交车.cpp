#include <bits/stdc++.h>
using namespace std;
int f(int w,int y){
   if(w<y) return 0;
   if(y==0) return 1;
   return f(w-1,y)+f(w,y-1);
}
int main(){
    cout<<f(18,18);
    return 0;
}