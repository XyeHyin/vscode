#include <bits/stdc++.h>
using namespace std;
int main(void){
    vector<long long> a(3);
    for (int i = 0; i < 3; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << a[0] << "->" << a[1] << "->" << a[2] << endl;
}