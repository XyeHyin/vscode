#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int cnt = 0;
    while(n--){
        int a, b;
        cin >> a >> b;
        if(b<a) cnt++;
    }
    cout << cnt << endl;
    return 0;
}