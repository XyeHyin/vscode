#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, max_val, min_val;
    cin >> a >> b >> c;
    max_val = max(max(a, b), c);
    min_val = min(min(a, b), c);
    cout << min_val << " " << a + b + c - max_val - min_val << " " << max_val << endl;
}