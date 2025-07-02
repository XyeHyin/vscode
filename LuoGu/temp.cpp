#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, s;
    int num = 1;
    cin >> n;
    for (int i = 0;i<n;i++){
        for (int j = 0; j <= n - 1;j++){
            if(num<10){
                cout << "0" << num;
            }else cout << num;
            num++;
        }
        cout << endl;
    }
        return 0;
}