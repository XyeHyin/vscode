#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, i;
    cin >> n>>i;
    for (int j = 1;;j++){
        bool flag = true;
        int tmp = j;
        tmp =tmp*n+i;
        for (int k = 1; k < n;k++){
            // cout<<tmp<<endl;
            if(tmp%(n-1)!=0){
                flag = false;
                break;
            }
            tmp = tmp / (n - 1) *n+ i;
        }
       if(flag){
           cout << tmp << endl;
           break;
       }
    }
        return 0;
}