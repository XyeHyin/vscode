#include <bits/stdc++.h>
using namespace std;
string dic[]={ "January", "February", "March","April",   "May",      "June","July",    "August",   "September","October", "November", "December"};
int main(){
    int _ = 12,money=2000,cnt=0,sheng=0;
    for(int i=0;i<_;i++){
        int x;
        cin>>x;
        if(x>money){
            cout<<"You need do some change in "<<dic[i]<<endl;
            return 0;
        }
        sheng+=money-x;
        cnt+=(sheng/100)*100;
        sheng%=100;
    }
    cout<<sheng+cnt*1.3<<endl;
    return 0;
}