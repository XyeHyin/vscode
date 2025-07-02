#include <bits/stdc++.h>
using namespace std;
int main(){
    int l, r;
    cin >> l >> r;  
    vector<int> a(10,0);
    for (int i = l;i<=r;i++){
        int tmp = i;
        while(tmp){
            a[tmp%10] ++;
            tmp /= 10;
        }
    }
    if(l<=0) a[0]++;
    cout << a[0];
    return 0;
}