#include <bits/stdc++.h>
using namespace std;
int main(){
    int max = 0,ans = 0;
    for (int i = 0; i < 10; i++){
        int temp;
        cin >> temp;
        if(max<temp){
            max = temp;
            ans = i;
        }
    }
    cout << ans << endl;
}