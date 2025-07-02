#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[1012] = {0};
    for (int j = 0; j < 10000;j++){
        int cnt = 0;
    int x, y;
    for (int i = 0; i < 1012;i++){
        x = rand() % (2024-2*i);
        do{ y = rand() % (2024-2*i);
        }while(x==y);
       
        if(x/2==y/2) cnt++;
    }
    a[cnt]++;
    }
    for(int j = 0; j < 1012;j++){
        cout << j << ": " << a[j] << endl;
    }
        return 0;
}