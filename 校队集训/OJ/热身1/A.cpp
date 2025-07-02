#include <bits/stdc++.h>
using namespace std;
int main(){
    int day = 0;
    for (int i = 2001; i <= 2023; i++) {
        if((i%4==0&&i%100!=0)||i%400==0){
            day += 366;
        }else{
            day += 365;
        }
    }
    cout << day+2 << endl;
        return 0;
}