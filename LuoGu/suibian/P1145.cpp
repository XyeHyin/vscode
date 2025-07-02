#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int sum = 1;
    int j = 4;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    for(int i=2; i<n; i++){
        sum = sum * sum + j;
        j++;
    }
    cout << sum << endl;
    return 0;
}