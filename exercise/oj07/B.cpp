#include <bits/stdc++.h>
using namespace std;
int main(void){
    int sumzheng = 0,sumfu = 0,cntfu = 0,cntzheng = 0;
    while(true){
        int temp;
        cin >> temp;
        if(temp<0) {
            sumfu += temp;
            cntfu++;
        }
        else if(temp==0) break;
        else {
         sumzheng += temp;
         cntzheng++;
         }
    }
    double avgfu = (double)sumfu / cntfu;
    double avgzheng = (double)sumzheng / cntzheng;
    printf("%.6f\n%.6f\n", avgzheng, avgfu);
}