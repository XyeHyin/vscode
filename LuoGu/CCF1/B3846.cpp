#include <bits/stdc++.h>
using namespace std;
bool isrun(int year){
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return true;
    return false;
}
int main(){
    int a, b;
    cin>>a>>b;
    int ans = 0;
    for (int i = a+1; i < b; i++) {
        if (isrun(i)) {
            ans += i;
        } 
    }
    cout << ans << endl;
        return 0;
}