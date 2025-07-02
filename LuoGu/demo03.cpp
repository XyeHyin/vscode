#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int a, b,temp,num;
    cin >> a >> b;
    temp = max(a, b);
    for (int i = temp;; i++){
       if(i%a==0 && i%b==0){
           num = i;
           break;
       } 
       else continue;
    }
        cout << num << endl;
    return 0;
}