#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,counta=0,countb=0;
    double avga, avgb, suma, sumb;
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        if(i%k==0){
            suma += i;
            counta++;
        }else{
            sumb += i;
            countb++;
        }
    }
            avga=double (suma)/counta;
            avgb=double (sumb)/countb;
            printf("%.1lf %.1lf", avga, avgb);
    }