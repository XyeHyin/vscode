#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    n = 1012;
    m = 2 * n;
    int a[n] = {0};
    for (int j = 0; j < 10000;j++){
        int cnt = 0;
    int x, y;
    for (int i = 0; i < n;i++){
        x = rand() % (m-2*i);
        do{ y = rand() % (m-2*i);
        }while(x==y);
       
        if(x/2==y/2) cnt++;
    }
    a[cnt]++;
    }
    int max=max_element(a,a+n)-a;
    cout << max << endl;
        return 0;
}