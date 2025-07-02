#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> h(n+1);
    h[0] = h[1] = 1;
    for (int i = 2;i<=n;i++){
        for (int j = 0; j < i;j++){
            h[i]+=h[j]*h[i-j-1];
        }
    }
    cout << h[n];
        return 0;
}