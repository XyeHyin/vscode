#include <bits/stdc++.h>
using namespace std;
int main(){
    int s,v,hour,minute;
    cin >> s >> v;
    int t =ceil(1.0*s / v)+ 10;
    int tt = 8 * 60 - t;
    if(tt<=0){
        hour = (24 * 60 + 8 * 60 - t)/60;
        minute=(24 * 60 + 8 * 60 - t)%60;
    }else{
    hour = tt / 60;
    minute = tt % 60;
}
    printf("%02d:%02d",hour,minute);
}