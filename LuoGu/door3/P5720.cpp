#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, day = 1;
    cin >> a;
    while(a>1){
        a = a / 2;
        day++;
    }
    cout << day << endl;
}