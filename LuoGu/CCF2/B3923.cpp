#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, m, n;
    cin >> a >> b >> m >> n;
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    int sum = a + b;
    for(int i = 2; i < n; i++){
        if ((v[i - 1])>=m) break;
        v.push_back((v[i - 1]+ v[i - 2]));
        sum += v[i];
    }
    cout << sum;
    return 0;
}