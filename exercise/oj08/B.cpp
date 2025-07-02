#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,sum=0;
    cin >> n;
    for (int i = 1; i <= n;i++){
        bool flag = false;
        if(i%7==0){
            flag = true;
            sum += i;
        }
        int temp = i;
        if(!flag){
            while(temp){
                if(temp%10==7){
                    sum += i;
                    break;
                }
                temp /= 10;
            }
        }
    }
    cout << sum << endl;
}