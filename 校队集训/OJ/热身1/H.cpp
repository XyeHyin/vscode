#include <bits/stdc++.h>
using namespace std;
int date[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    int birthdate = 0;
    for(int i=1;i<=7;i++){
        birthdate += date[i];
    }
    birthdate += 9;
    int now = 0;
    int a, b;
    cin >> a >> b;
    for(int i=1;i<=a-1;i++){
        now += date[i];
    }
    now += b;
    if(now-birthdate<0){
        cout << birthdate-now << endl;
        }else{
         cout<<(365-now)+birthdate<<endl;
        }
    return 0;
}